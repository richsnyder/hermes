#include "generator/cpp/generator.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

generator::generator()
  : m_blueprint(nullptr)
{
  // empty
}

void
generator::open(const std::string& a_project, const std::string& a_directory)
{
  m_project = a_project;
  m_hpp_path = a_directory + "/" + a_project + ".hpp";
  m_cpp_path = a_directory + "/" + a_project + ".cpp";
  m_hpp.open(m_hpp_path);
  m_cpp.open(m_cpp_path);
  m_hpp << tabsize(2);
  m_cpp << tabsize(2);
}

void
generator::write(const state::blueprint& a_blueprint)
{
  m_blueprint = &a_blueprint;
  write_header();
  write_enumerations();
  write_forwards();
  write_aliases();
  write_structures();
  write_constants();
  write_interfaces();
  write_footer();
  m_blueprint = nullptr;
}

void
generator::close()
{
  m_project.clear();
  m_hpp_path.clear();
  m_cpp_path.clear();
  m_hpp.close();
  m_cpp.close();
}

void
generator::write_header()
{
  auto guard = include_guard();
  auto parts = split_namespace();
  m_hpp << "#ifndef " << guard << std::endl;
  m_hpp << "#define " << guard << std::endl << std::endl;
  m_hpp << "#include <hermes.hpp>" << std::endl << std::endl;
  m_cpp << "#include \"" << m_hpp_path << "\"" << std::endl << std::endl;
  for (auto part = parts.begin(); part != parts.end(); ++part)
  {
    m_hpp << tab << "namespace " << *part << " {" << std::endl;
    m_cpp << tab << "namespace " << *part << " {" << std::endl;
  }
  m_hpp << std::endl;
  m_cpp << std::endl;
}

void
generator::write_enumerations()
{
  for (auto ptr : m_blueprint->enumerations())
  {
    write_enumeration(*ptr);
  }
}

void
generator::write_forwards()
{
  std::set<std::string> names;
  for (auto ptr : m_blueprint->aliases())
  {
    forwards(ptr->type(), names);
  }
  for (const auto& name : names)
  {
    m_hpp << tab << "class " << name << ";" << std::endl;
  }
}

void
generator::write_aliases()
{
  for (auto ptr : m_blueprint->aliases())
  {
    write_alias(*ptr);
  }
  m_hpp << std::endl;
}

void
generator::write_structures()
{
  for (auto ptr : m_blueprint->structures())
  {
    write_structure(*ptr);
  }
  for (auto ptr : m_blueprint->exceptions())
  {
    write_structure(*ptr);
  }
}

void
generator::write_constants()
{
  for (const auto& c : m_blueprint->constants())
  {
    write_constant(c);
  }
  m_hpp << std::endl;
}

void
generator::write_interfaces()
{
  for (const auto& i : m_blueprint->interfaces())
  {
    write_interface(i);
  }
  m_hpp << std::endl;
}

void
generator::write_footer()
{
  auto guard = include_guard();
  auto parts = split_namespace();
  for (auto part = parts.rbegin(); part != parts.rend(); ++part)
  {
    m_hpp << tab << "} // namespace " << *part << std::endl;
    m_cpp << tab << "} // namespace " << *part << std::endl;
  }
  m_hpp << std::endl << "#endif // " << guard << std::endl;
}

void
generator::write_enumeration(const state::enumeration& a_enumeration)
{
  std::size_t n = 0;
  std::size_t size = a_enumeration.items().size();
  m_hpp << tab << "enum " << a_enumeration.name() << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;
  for (const auto& item : a_enumeration.items())
  {
    m_hpp << tab << item.name();
    if (item.value())
    {
      m_hpp << " = " << *item.value();
    }
    m_hpp << ((++n < size) ? "," : "") << std::endl;
  }
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl << std::endl;
}

void
generator::write_alias(const state::alias& a_alias)
{
  pointer type = translate(a_alias.type());
  std::string type_name = type->name();
  std::string name = a_alias.name();
  m_hpp << tab << "typedef " << type_name << " " << name << ";" << std::endl;
}

void
generator::write_structure(const state::structure& a_structure)
{
  std::string name = a_structure.name();
  m_hpp << tab << "class " << name << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << tab << "public:" << std::endl;
  m_hpp << indent;
  constructors(a_structure);
  m_hpp << std::endl;
  for (const auto& field_ : a_structure.fields())
  {
    getter(name, field_);
  }
  for (const auto& field_ : a_structure.fields())
  {
    setter(name, field_);
  }
  m_hpp << std::endl;
  decoder(a_structure);
  encoder(a_structure);
  m_hpp << unindent;
  m_hpp << tab << "private:" << std::endl;
  m_hpp << indent;
  for (const auto& field_ : a_structure.fields())
  {
    member(field_);
  }
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl << std::endl;
}

void
generator::write_constant(const state::constant& a_constant)
{
  pointer constant_type = translate(a_constant.type());
  m_hpp << tab
      << "const " << constant_type->value_type()
      << " " << a_constant.name()
      << " = " << a_constant.value()
      << ";" << std::endl;
}

void
generator::write_interface(const state::interface& a_interface)
{
  m_hpp << tab << "class " << a_interface.name() << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << tab << "public:" << std::endl;
  m_hpp << indent;
  client(a_interface);
  m_hpp << std::endl;
  server(a_interface);
  m_hpp << unindent;
  m_hpp << tab << "protected:" << std::endl;
  m_hpp << indent;
  rpc(a_interface);
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;
}

char
generator::toguard(char a_char) const
{
  if (a_char <= 0x2F || a_char >= 0x7B) return '_';
  if (a_char >= 0x3A && a_char <= 0x60) return '_';
  return toupper(a_char);
}

std::string
generator::include_guard() const
{
  std::string guard = m_project;
  std::for_each(guard.begin(), guard.end(), [&](char& c){ c = toguard(c); });
  return guard + "_HPP";
}

std::vector<std::string>
generator::split_namespace() const
{
  return split(m_blueprint->get_space("cpp"));
}

std::string
generator::member(const std::string& a_variable) const
{
  return "m_" + a_variable;
}

std::string
generator::param(const std::string& a_variable) const
{
  return "a_" + a_variable;
}

void
generator::parameters(std::ostream& a_out, const field_vector& a_fields)
{
  bool first = true;
  for (const auto& field_ : a_fields)
  {
    pointer field_type = translate(field_.type());
    std::string type = field_type->param_type();
    std::string argument = param(field_.name());
    a_out << (first ? "" : ", ") << type << " " << argument;
    first = false;
  }
}

void
generator::references(std::ostream& a_out, const field_vector& a_fields)
{
  bool first = true;
  for (const auto& field_ : a_fields)
  {
    pointer field_type = translate(field_.type());
    std::string type = field_type->reference();
    std::string argument = param(field_.name());
    a_out << (first ? "" : ", ") << type << " " << argument;
    first = false;
  }
}

void
generator::arguments(std::ostream& a_out, const field_vector& a_fields)
{
  bool first = true;
  for (const auto& field_ : a_fields)
  {
    a_out << (first ? "" : ", ") << param(field_.name());
    first = false;
  }
}

void
generator::variables(std::ostream& a_out, const field_vector& a_fields)
{
  for (const auto& field_ : a_fields)
  {
    pointer field_type = translate(field_.type());
    std::string value_type = field_type->value_type();
    std::string argument = param(field_.name());
    a_out << tab << value_type << " " << argument << ";" << std::endl;
  }
}

void
generator::archive(std::ostream& a_out, const field_vector& a_fields)
{
  bool first = true;
  a_out << tab << "bool status =";
  for (const auto& field_ : a_fields)
  {
    a_out << (first ? " " : " && ") << "archive(" << param(field_.name()) << ")";
    first = false;
  }
  a_out << ";" << std::endl;
}

void
generator::initialization(std::ostream& a_out, const field_vector& a_fields)
{
  bool first = true;
  std::string result;
  a_out << indent;
  for (const auto& field_ : a_fields)
  {
    std::string name = field_.name();
    std::string pre = first ? ": " : ", ";
    std::string var = member(name);
    std::string arg = param(name);
    a_out << tab << pre << var << "(" << arg << ")" << std::endl;
    first = false;
  }
  a_out << unindent;
}

void
generator::empty_body(std::ostream& a_out)
{
  a_out << tab << "{" << std::endl;
  a_out << indent;
  a_out << tab << "// empty" << std::endl;
  a_out << unindent;
  a_out << tab << "}" << std::endl;
  a_out << std::endl;
}

void
generator::forwards(std::shared_ptr<state::datatype> a_datatype,
                    std::set<std::string>& a_forwards) const
{
  if (a_datatype->is_structure())
  {
    a_forwards.insert(a_datatype->name());
  }
  else if (a_datatype->is_map())
  {
    auto as_map = std::dynamic_pointer_cast<state::map>(a_datatype);
    forwards(as_map->key_type(), a_forwards);
    forwards(as_map->value_type(), a_forwards);
  }
  else if (a_datatype->is_set())
  {
    auto as_set = std::dynamic_pointer_cast<state::set>(a_datatype);
    forwards(as_set->key_type(), a_forwards);
  }
  else if (a_datatype->is_vector())
  {
    auto as_vector = std::dynamic_pointer_cast<state::vector>(a_datatype);
    forwards(as_vector->value_type(), a_forwards);
  }
}

std::shared_ptr<sizer>
generator::get_size(const std::string& a_variable, pointer a_datatype) const
{
  return a_datatype->size(a_variable);
}

std::shared_ptr<sizer>
generator::get_size(const field_vector& a_fields) const
{
  if (a_fields.empty())
  {
    return std::make_shared<sizer>("{}", 0);
  }

  bool first = true;
  pointer field_type = nullptr;
  std::shared_ptr<sizer> root = nullptr;
  std::shared_ptr<sizer> next = nullptr;
  for (const auto& field_ : a_fields)
  {
    field_type = translate(field_.type());
    next = field_type->size(param(field_.name()));
    if (first)
    {
      root = next;
      first = false;
    }
    else
    {
      root->link(next);
    }
  }
  return root;
}

void
generator::constructors(const state::structure& a_structure)
{
  std::string name = a_structure.name();

  m_hpp << tab << name << "() = default;" << std::endl;
  m_hpp << tab << name << "(const " << name << "&) = default;" << std::endl;
  m_hpp << tab << name << "(";
  parameters(m_hpp, a_structure.fields());
  m_hpp << ");" << std::endl;

  m_cpp << tab << name << "::" << name << "(";
  parameters(m_cpp, a_structure.fields());
  m_cpp << ")" << std::endl;
  initialization(m_cpp, a_structure.fields());
  empty_body(m_cpp);
}

void
generator::decoder(const state::structure& a_structure)
{
  m_hpp << tab << "bool read(hermes::iarchive& a_in);" << std::endl;

  m_cpp << tab << "bool" << std::endl;
  m_cpp << tab << a_structure.name() << "::read(hermes::iarchive& a_in)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "return";
  bool first = true;
  for (const auto& field_ : a_structure.fields())
  {
    m_cpp << (first ? " " : " && ") << "a_in(" << member(field_.name()) << ")";
    first = false;
  }
  m_cpp << ";" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::encoder(const state::structure& a_structure)
{
  m_hpp << tab << "bool write(hermes::oarchive& a_out);" << std::endl;

  m_cpp << tab << "bool" << std::endl;
  m_cpp << tab << a_structure.name() << "::write(hermes::oarchive& a_out)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "return";
  bool first = true;
  for (const auto& field_ : a_structure.fields())
  {
    m_cpp << (first ? " " : " && ") << "a_out(" << member(field_.name()) << ")";
    first = false;
  }
  m_cpp << ";" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::member(const state::field& a_field)
{
  pointer field_type = translate(a_field.type());
  std::string type = field_type->value_type();
  std::string name = member(a_field.name());
  m_hpp << tab << type << " " << name << ";" << std::endl;
}

void
generator::getter(const std::string& a_class, const state::field& a_field)
{
  pointer field_type = translate(a_field.type());
  std::string type = field_type->const_reference();
  std::string method = "get_" + a_field.name();
  std::string var = member(a_field.name());

  m_hpp << tab << type << " " << method << "() const;" << std::endl;

  m_cpp << tab << type << std::endl;
  m_cpp << tab << a_class << "::" << method << "() const" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "return " << var << ";" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::setter(const std::string& a_class, const state::field& a_field)
{
  pointer field_type = translate(a_field.type());
  std::string type = field_type->param_type();
  std::string method = "set_" + a_field.name();
  std::string var = member(a_field.name());
  std::string arg = param(a_field.name());
  std::string arglist = "(" + type + " " + arg + ")";

  m_hpp << tab << "void " << method << arglist << ";" << std::endl;

  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << a_class << "::" << method << arglist << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << var << " = " << arg << ";" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::client(const state::interface& a_interface)
{
  std::string name = a_interface.name();
  std::string args="void* a_context, const std::string& a_endpoint, int a_type";

  m_hpp << tab << "class client : public hermes::client" << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << tab << "public:" << std::endl;
  m_hpp << indent;
  m_hpp << tab << "client(" << args << ");" << std::endl;
  m_hpp << tab << "virtual ~client();" << std::endl;
  m_hpp << std::endl;

  m_cpp << tab << name << "::client::client(" << args << ")" << std::endl;
  m_cpp << indent;
  m_cpp << tab << ": hermes::client(a_context, a_endpoint, a_type)" <<std::endl;
  m_cpp << unindent;
  empty_body(m_cpp);
  m_cpp << tab << name << "::client::~client()" << std::endl;
  empty_body(m_cpp);

  std::int32_t header_id = 0;
  for (const auto& procedure_ : a_interface.procedures())
  {
    header_id++;
    client_procedure(name, header_id, procedure_);
  }

  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;
}

void
generator::server(const state::interface& a_interface)
{
  std::string name = a_interface.name();
  std::string args="void* a_context, const std::string& a_endpoint, int a_type";
  std::string error_msg = "\"Received a request for an undefined procedure\"";

  m_hpp << tab << "class server : public hermes::server" << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << tab << "public:" << std::endl;
  m_hpp << indent;
  m_hpp << tab << "server(" << args << ");" << std::endl;
  m_hpp << tab << "virtual ~server();" << std::endl;
  m_hpp << std::endl;
  m_hpp << tab << "void serve_once();" << std::endl << std::endl;

  m_cpp << tab << name << "::server::server(" << args << ")" << std::endl;
  m_cpp << indent;
  m_cpp << tab << ": hermes::server(a_context, a_endpoint, a_type)" <<std::endl;
  m_cpp << unindent;
  empty_body(m_cpp);
  m_cpp << tab << name << "::server::~server()" << std::endl;
  empty_body(m_cpp);
  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << name << "::server::serve_once()" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "try" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "hermes::request_header header(m_socket);" << std::endl;
  m_cpp << tab << "switch (header.number())" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;

  std::int32_t header_id = 0;
  for (const auto& procedure_ : a_interface.procedures())
  {
    header_id++;
    server_procedure(header_id, procedure_);
  }

  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;

  m_cpp << tab << "default:" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "int code;" << std::endl;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << "bool more = header.more();" << std::endl;
  m_cpp << tab << "while (more)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "code = zmq_msg_init(&message);" << std::endl;
  m_cpp << tab << "code = zmq_msg_recv(&message, m_socket, 0);" << std::endl;
  m_cpp << tab << "more = zmq_msg_more(&message);" << std::endl;
  m_cpp << tab << "code = zmq_msg_close(&message);" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "hermes::reply_header(0, false).send(m_socket);" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "catch (std::exception& e)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "hermes::reply_header(0, false).send(m_socket);" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::rpc(const state::interface& a_interface)
{
  m_hpp << tab << "struct rpc" << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;

  std::int32_t header_id = 0;
  std::string name = a_interface.name();
  for (const auto& procedure_ : a_interface.procedures())
  {
    header_id++;
    rpc_procedure(name, header_id, procedure_);
  }

  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;
}

void
generator::client_procedure(const std::string& a_interface,
                            std::int32_t a_id,
                            const state::procedure& a_procedure)
{
  std::int32_t result_id = 1;
  bool is_void = a_procedure.result()->is_void();
  bool is_empty = a_procedure.parameters().empty();
  pointer result_type = translate(a_procedure.result());
  std::string result = result_type->value_type();
  std::string method = a_procedure.name();

  m_hpp << tab << result << " " << method << "(";
  parameters(m_hpp, a_procedure.parameters());
  m_hpp << ");" << std::endl;

  m_cpp << tab << result << std::endl;
  m_cpp << tab << a_interface << "::client::" << method << "(";
  parameters(m_cpp, a_procedure.parameters());
  m_cpp << ")" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "hermes::request_header(";
  m_cpp << a_id << ", " << (is_empty ? "false" : "true");
  m_cpp << ").send(m_socket);" << std::endl;
  if (!is_empty)
  {
    m_cpp << tab << "rpc::" << method << "::req::send(m_socket, ";
    arguments(m_cpp, a_procedure.parameters());
    m_cpp << ");" << std::endl;
  }
  m_cpp << tab << "hermes::reply_header header(m_socket);" << std::endl;
  m_cpp << tab << "switch (header.number())" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "case " << result_id << ":" << std::endl;
  m_cpp << indent;
  if (is_void)
  {
    m_cpp << tab << "if (header.more())" << std::endl;
    m_cpp << tab << "{" << std::endl;
    m_cpp << indent;
    m_cpp << tab << "throw hermes::error(\"Received a reply from \\\"" << method << "\\\" but expected void\");" << std::endl;
    m_cpp << unindent;
    m_cpp << tab << "}" << std::endl;
    m_cpp << tab << "return;" << std::endl;
  }
  else
  {
    m_cpp << tab << "if (!header.more())" << std::endl;
    m_cpp << tab << "{" << std::endl;
    m_cpp << indent;
    m_cpp << tab << "throw hermes::error(\"Expected a reply from \\\"" << method << "\\\" data but received nothing\");" << std::endl;
    m_cpp << unindent;
    m_cpp << tab << "}" << std::endl;
    m_cpp << tab << "return rpc::" << method << "::rep::recv(m_socket);" << std::endl;
  }
  m_cpp << unindent;
  for (const auto& e : a_procedure.exceptions())
  {
    ++result_id;
    m_cpp << tab << "case " << result_id << ":" << std::endl;
    m_cpp << indent;
    m_cpp << tab << "if (!header.more())" << std::endl;
    m_cpp << tab << "{" << std::endl;
    m_cpp << indent;
    m_cpp << tab << "throw hermes::error(\"Expected an \\\"" << e->name() << "\\\" exception object but received nothing\");" << std::endl;
    m_cpp << unindent;
    m_cpp << tab << "}" << std::endl;
    m_cpp << tab << "throw rpc::" << method << "::throw_" << e->name() << "::recv(m_socket);" << std::endl;
    m_cpp << unindent;
  }
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "throw hermes::error(\"Unexpected result from \\\"" << method << "\\\"\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::server_procedure(std::int32_t a_id,
                            const state::procedure& a_procedure)
{
  std::int32_t result_id = 1;
  bool is_void = a_procedure.result()->is_void();
  bool is_empty = a_procedure.parameters().empty();
  bool is_throwing = a_procedure.exceptions().size() > 0;
  pointer result_type = translate(a_procedure.result());
  std::string result = result_type->value_type();
  std::string method = a_procedure.name();

  m_hpp << tab << "virtual " << result << " " << method << "(";
  parameters(m_hpp, a_procedure.parameters());
  m_hpp << ") = 0;" << std::endl;

  m_cpp << tab << "case " << a_id << ":" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  if (!is_void)
  {
    m_cpp << tab << result << " result;" << std::endl;
  }
  if (!is_empty)
  {
    variables(m_cpp, a_procedure.parameters());
  }
  if (is_throwing)
  {
    m_cpp << tab << "try" << std::endl;
    m_cpp << tab << "{" << std::endl;
    m_cpp << indent;
  }
  if (!is_empty)
  {
    m_cpp << tab << "rpc::" << method << "::req::recv(m_socket, ";
    arguments(m_cpp, a_procedure.parameters());
    m_cpp << ");" << std::endl;
  }
  m_cpp << tab << (is_void ? "" : "result = ") << method << "(";
  arguments(m_cpp, a_procedure.parameters());
  m_cpp << ");" << std::endl;
  m_cpp << tab << "hermes::reply_header(";
  m_cpp << result_id << ", " << (is_void ? "false" : "true");
  m_cpp << ").send(m_socket);" << std::endl;
  if (!is_void)
  {
    m_cpp << tab << "rpc::" << method << "::rep::send(m_socket, result);" << std::endl;
  }
  if (is_throwing)
  {
    m_cpp << unindent;
    m_cpp << tab << "}" << std::endl;
  }
  for (auto e : a_procedure.exceptions())
  {
    ++result_id;
    pointer exception_type = translate(e);
    std::string ref = exception_type->reference();
    std::string val = exception_type->value_type();
    std::string what = param(exception_type->name());
    m_cpp << tab << "catch (" << ref << " " << what << ")" << std::endl;
    m_cpp << tab << "{" << std::endl;
    m_cpp << indent;
    m_cpp << tab << "hermes::reply_header(";
    m_cpp << result_id << ", true";
    m_cpp << ").send(m_socket);" << std::endl;
    m_cpp << tab << "rpc::" << method << "::throw_" << val << "::send(m_socket, " << what << ");" << std::endl;
    m_cpp << unindent;
    m_cpp << tab << "}" << std::endl;
  }
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "break;" << std::endl;
  m_cpp << unindent;
}

void
generator::rpc_procedure(const std::string& a_interface,
                         std::int32_t a_id,
                         const state::procedure& a_procedure)
{
  std::string method = a_procedure.name();
  bool is_void = a_procedure.result()->is_void();
  bool is_empty = a_procedure.parameters().empty();

  m_hpp << tab << "struct " << method << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;
  if (!is_empty)
  {
    rpc_request(a_interface, method, a_procedure.parameters());
  }
  if (!is_void)
  {
    rpc_reply(a_interface, method, a_procedure.result());
  }
  for (auto ptr : a_procedure.exceptions())
  {
    rpc_exception(a_interface, method, ptr);
  }
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;
}

void
generator::rpc_request(const std::string& a_interface,
                       const std::string& a_method,
                       const field_vector& a_parameters)
{
  std::string prefix = a_interface + "::rpc::" + a_method + "::req";

  m_hpp << tab << "struct req" << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;
  m_hpp << tab << "static void send(void* a_socket, ";
  parameters(m_hpp, a_parameters);
  m_hpp << ");" << std::endl;
  m_hpp << tab << "static void recv(void* a_socket, ";
  references(m_hpp, a_parameters);
  m_hpp << ");" << std::endl;
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;

  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << prefix << "::send(void* a_socket, ";
  parameters(m_cpp, a_parameters);
  m_cpp << ")" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << sizevar("size", get_size(a_parameters));
  m_cpp << tab << "hermes::oarchive archive(size);" << std::endl;
  archive(m_cpp, a_parameters);
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to serialize a \\\"" << a_method << "\\\" request\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "int code = zmq_msg_init_data(&message, archive.data(), size, hermes::free, nullptr);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_send(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "if (code != size)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to send a \\\"" << a_method << "\\\" request\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;

  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << prefix << "::recv(void* a_socket, ";
  references(m_cpp, a_parameters);
  m_cpp << ")" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << "zmq_msg_init(&message);" << std::endl;
  m_cpp << tab << "int code = zmq_msg_recv(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << std::endl;
  m_cpp << tab << "hermes::iarchive archive(zmq_msg_data(&message), zmq_msg_size(&message));" << std::endl;
  archive(m_cpp, a_parameters);
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to deserialize a \\\"" << a_method << "\\\" request\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_close(&message);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::rpc_reply(const std::string& a_interface,
                     const std::string& a_method,
                     std::shared_ptr<state::datatype> a_result)
{
  pointer result_type = translate(a_result);
  std::string reference_type = result_type->const_reference();
  std::string value_type = result_type->value_type();

  std::string prefix = a_interface + "::rpc::" + a_method + "::rep";

  m_hpp << tab << "struct rep" << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;
  m_hpp << tab << "static void send(void* a_socket, ";
  m_hpp << reference_type << " a_result";
  m_hpp << ");" << std::endl;
  m_hpp << tab << "static " << value_type;
  m_hpp << " recv(void* a_socket);" << std::endl;
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;

  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << prefix << "::send(void* a_socket, ";
  m_cpp << reference_type << " a_result";
  m_cpp << ")" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << sizevar("size", get_size("a_result", result_type));
  m_cpp << tab << "hermes::oarchive archive(size);" << std::endl;
  m_cpp << tab << "bool status = archive(a_result);" << std::endl;
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to serialize a \\\"" << a_method << "\\\" reply\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << "int code = zmq_msg_init_data(&message, archive.data(), size, hermes::free, nullptr);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_send(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "if (code != size)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to send a \\\"" << a_method << "\\\" reply\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;

  m_cpp << tab << value_type << std::endl;
  m_cpp << tab << prefix << "::recv(void* a_socket)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << value_type << " a_result;" << std::endl;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << "zmq_msg_init(&message);" << std::endl;
  m_cpp << tab << "int code = zmq_msg_recv(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "hermes::iarchive archive(zmq_msg_data(&message), zmq_msg_size(&message));" << std::endl;
  m_cpp << tab << "bool status = archive(a_result);" << std::endl;
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to deserialize a \\\"" << a_method << "\\\" reply\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_close(&message);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "return a_result;" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

void
generator::rpc_exception(const std::string& a_interface,
                         const std::string& a_method,
                         std::shared_ptr<state::exception> a_exception)
{
  pointer exception_type = translate(a_exception);
  std::string param_type = exception_type->param_type();
  std::string value_type = exception_type->value_type();
  std::string variable = param(exception_type->name());
  std::string name = exception_type->name();
  std::string class_name = "throw_" + name;

  std::string prefix = a_interface + "::rpc::" + a_method + "::" + class_name;

  m_hpp << tab << "struct " << class_name << std::endl;
  m_hpp << tab << "{" << std::endl;
  m_hpp << indent;
  m_hpp << tab << "static void send(void* a_socket, ";
  m_hpp << param_type << " " << variable;
  m_hpp << ");" << std::endl;
  m_hpp << tab << "static " << value_type;
  m_hpp << " recv(void* a_socket);" << std::endl;
  m_hpp << unindent;
  m_hpp << tab << "};" << std::endl;

  m_cpp << tab << "void" << std::endl;
  m_cpp << tab << prefix << "::send(void* a_socket, ";
  m_cpp << param_type << " " << variable;
  m_cpp << ")" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << sizevar("size", get_size("a_result", exception_type));
  m_cpp << tab << "hermes::oarchive archive(size);" << std::endl;
  m_cpp << tab << "bool status = archive(" << variable << ");" << std::endl;
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to serialize a \\\"" << name << "\\\" exception\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "int code = zmq_msg_init_data(&message, archive.data(), size, hermes::free, nullptr);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_send(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "if (code != size)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to send a \\\"" << name << "\\\" exception\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;

  m_cpp << tab << value_type << std::endl;
  m_cpp << tab << prefix << "::recv(void* a_socket)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << value_type << " a_result;" << std::endl;
  m_cpp << tab << "zmq_msg_t message;" << std::endl;
  m_cpp << tab << "zmq_msg_init(&message);" << std::endl;
  m_cpp << tab << "int code = zmq_msg_recv(&message, a_socket, 0);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "hermes::iarchive archive(zmq_msg_data(&message), zmq_msg_size(&message));" << std::endl;
  m_cpp << tab << "bool status = archive(a_result);" << std::endl;
  m_cpp << tab << "if (!status)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(\"Failed to deserialize an \\\"" << a_method << "\\\" exception\");" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "code = zmq_msg_close(&message);" << std::endl;
  m_cpp << tab << "if (code < 0)" << std::endl;
  m_cpp << tab << "{" << std::endl;
  m_cpp << indent;
  m_cpp << tab << "throw hermes::error(zmq_strerror(errno));" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl;
  m_cpp << tab << "return a_result;" << std::endl;
  m_cpp << unindent;
  m_cpp << tab << "}" << std::endl << std::endl;
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
