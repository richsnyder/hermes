#include "generator/python/generator.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

generator::generator()
  : m_blueprint(nullptr)
{
  // empty
}

void
generator::open(const std::string& a_project, const std::string& a_directory)
{
  m_project = a_project;
  m_py_path = a_directory + "/" + a_project + ".py";
  m_py.open(m_py_path);
  m_py << tabsize(4);
}

void
generator::write(const state::blueprint& a_blueprint)
{
  m_blueprint = &a_blueprint;
  write_header();
  write_structures();
  write_interfaces();
  m_blueprint = nullptr;

  // write_enumerations();
  // write_constants();
}

void
generator::close()
{
  m_project.clear();
  m_py_path.clear();
  m_py.close();
}

void
generator::write_header()
{
  using std::endl;
  m_py << tab << "import hermes" << endl;
  m_py << tab << "import xdrlib" << endl;
  m_py << endl;
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
generator::write_interfaces()
{
  for (const auto& i : m_blueprint->interfaces())
  {
    write_interface(i);
  }
}

void
generator::write_structure(const state::structure& a_structure)
{
  using std::endl;

  auto name = to_camel(a_structure.name());
  const auto& fields = a_structure.fields();

  m_py << tab << "class " << name << ":" << endl;
  m_py << indent;
  constructor(fields);
  reader(fields);
  writer(fields);
  stringer(fields);
  m_py << unindent;
}

void
generator::write_interface(const state::interface& a_interface)
{
  m_py << tab << "class " << to_camel(a_interface.name()) << ":" << std::endl;
  m_py << indent;
  client(a_interface);
  server(a_interface);
  m_py << unindent;
}

void
generator::constructor(const field_vector& a_fields)
{
  using std::endl;
  using std::ostream;
  typedef const state::field& field_t;

  std::string name;
  auto argument = [](ostream& out, field_t f){
      pointer type = translate(f.type());
      out << f.name() << "=" << type->default_value();
    };

  m_py << tab << "def __init__(self";
  m_py << join(a_fields.begin(), a_fields.end(), argument).left(", ");
  m_py << "):" << endl;
  m_py << indent;
  for (const auto& field_ : a_fields)
  {
    name = field_.name();
    m_py << tab << "self." << name << " = " << name << endl;
  }
  m_py << unindent;
  m_py << endl;
}

void
generator::reader(const field_vector& a_fields)
{
  using std::endl;
  using std::ostream;
  typedef const state::field& field_t;

  std::string name;
  pointer type;

  auto member = [](ostream& out, field_t f){ out << f.name(); };
  auto ctor = join(a_fields.begin(), a_fields.end(), member).left("cls(").right(")");

  m_py << tab << "@classmethod" << std::endl;
  m_py << tab << "def read(cls, xdr):" << endl;
  m_py << indent;
  for (const auto& field_ : a_fields)
  {
    name = field_.name();
    type = translate(field_.type());
    type->unpack(m_py, name);
  }
  m_py << tab << "return " << ctor << endl;
  m_py << unindent;
  m_py << endl;
}

void
generator::writer(const field_vector& a_fields)
{
  using std::endl;

  std::string name;
  pointer type;

  m_py << tab << "def write(self, xdr):" << endl;
  m_py << indent;
  for (const auto& field_ : a_fields)
  {
    name = "self." + field_.name();
    type = translate(field_.type());
    type->pack(m_py, name);
  }
  m_py << unindent;
  m_py << endl;
}

void
generator::stringer(const field_vector& a_fields)
{
  using std::endl;
  using std::ostream;
  typedef const state::field& field_t;

  auto member = [](ostream& out, field_t f){ out << "self." << f.name(); };

  m_py << tab << "def __str__(self):" << endl;
  m_py << indent;
  m_py << tab << "return str(";
  m_py << join(a_fields.begin(), a_fields.end(), member).left("(").right(")");
  m_py << ")" << endl;
  m_py << unindent;
  m_py << endl;
}

void
generator::client(const state::interface& a_interface)
{
  using std::endl;

  auto header_id = 0;
  auto name = to_camel(a_interface.name());
  auto parent = "super(" + name + ".Client, self)";

  m_py << tab << "class Client(hermes.Client):" << endl;
  m_py << indent;
  m_py << tab << "def __init__(self, context, endpoint, type_):" << endl;
  m_py << indent;
  m_py << tab << parent << ".__init__(context, endpoint, type_)" << endl;
  m_py << endl;
  m_py << unindent;
  for (const auto& procedure_ : a_interface.procedures())
  {
    header_id++;
    client_method(procedure_, header_id);
  }
  m_py << unindent;
}

void
generator::server(const state::interface& a_interface)
{
  using std::endl;

  auto header_id = 0;
  auto name = to_camel(a_interface.name());
  auto parent = "super(" + name + ".Server, self)";
  auto error_message = "Received a request for an undefined procedure";

  m_py << tab << "class Server(hermes.Server):" << endl;
  m_py << indent;
  m_py << tab << "def __init__(self, context, endpoint, type_):" << endl;
  m_py << indent;
  m_py << tab << parent << ".__init__(context, endpoint, type_)" << endl;
  m_py << unindent;
  m_py << endl;
  m_py << tab << "def serve_once(self):" << endl;
  m_py << indent;
  m_py << tab << "try:" << endl;
  m_py << indent;
  m_py << tab << "header = hermes.RequestHeader.recv(self.socket)" << endl;
  for (const auto& procedure_ : a_interface.procedures())
  {
    header_id++;
    server_method(procedure_, header_id);
  }
  m_py << tab << "else:" << endl;
  m_py << indent;
  m_py << tab << "raise hermes.HermesError('" << error_message << "')" << endl;
  m_py << unindent;
  m_py << unindent;
  m_py << tab << "except:" << endl;
  m_py << indent;
  m_py << tab << "hermes.ReplyHeader.create(0x00, False).send(self.socket)" << endl;
  m_py << unindent;
  m_py << unindent;
  m_py << endl;

}

void
generator::client_method(const state::procedure& a_procedure, int a_id)
{
  using std::endl;
  using std::ostream;
  typedef const state::field& field_t;

  auto argument = [](ostream& out, field_t f){ out << f.name(); };
  auto pack = [&](field_t p){ translate(p.type())->pack(m_py, p.name()); };

  auto name = a_procedure.name();
  auto result = a_procedure.result();
  auto params = a_procedure.parameters();
  auto errors = a_procedure.exceptions();
  auto has_args = !params.empty();
  auto is_void = result->is_void();

  auto id = to_hex(a_id);
  auto more = has_args ? "True" : "False";
  auto req_header = "hermes.RequestHeader.create(" + id + ", " + more + ").send(self.socket)";
  auto rep_header = "hermes.ReplyHeader.recv(self.socket)";
  auto error_message = "Unexpected result from \"" + name + "()\"";

  m_py << tab << "def " << name << "(self";
  if (has_args)
  {
    m_py << join(params.begin(), params.end(), argument).left(", ");
  }
  m_py << "):" << endl;
  m_py << indent;

  m_py << tab << req_header << endl;
  if (has_args)
  {
    m_py << tab << "xdr = xdrlib.Packer()" << endl;
    std::for_each(params.begin(), params.end(), pack);
    m_py << tab << "self.socket.send(xdr.get_buffer())" << endl;
  }
  m_py << tab << "header = " << rep_header << endl;
  m_py << tab << "if header.number() == 0x01:" << endl;
  m_py << indent;
  if (is_void)
  {
    m_py << tab << "pass" << endl;
  }
  else
  {
    m_py << tab << "xdr = xdrlib.Unpacker(self.socket.recv())" << endl;
    translate(result)->unpack(m_py, "result");
    m_py << tab << "return result" << endl;
  }
  m_py << unindent;

  auto eid = 1;
  for (auto err : errors)
  {
    eid++;
    m_py << tab << "elif header.number() == " << to_hex(eid) << ":" << endl;
    m_py << indent;
    m_py << tab << "xdr = xdrlib.Unpacker(self.socket.recv())" << endl;
    translate(err)->unpack(m_py, "result");
    m_py << tab << "raise result" << endl;
    m_py << unindent;
  }

  m_py << tab << "else:" << endl;
  m_py << indent;
  m_py << tab << "raise hermes.HermesError('" << error_message << "')" << endl;
  m_py << unindent;

  m_py << unindent;
  m_py << endl;
}

void
generator::server_method(const state::procedure& a_procedure, int a_id)
{
  using std::endl;
  using std::ostream;
  typedef const state::field& field_t;

  auto argument = [](ostream& out, field_t f){ out << f.name(); };
  auto unpack = [&](field_t p){ translate(p.type())->unpack(m_py, p.name()); };

  auto name = a_procedure.name();
  auto result = a_procedure.result();
  auto params = a_procedure.parameters();
  auto errors = a_procedure.exceptions();
  auto has_args = !params.empty();
  auto has_errs = !errors.empty();
  auto is_void = result->is_void();

  auto id = to_hex(a_id);
  auto if_elif = (a_id == 1) ? "if" : "elif";
  auto reply_id = 1;

  m_py << tab << if_elif << " header.number() == " << id << ":" << endl;
  m_py << indent;
  if (has_args)
  {
    m_py << tab << "xdr = xdrlib.Unpacker(self.socket.recv())" << endl;
    std::for_each(params.begin(), params.end(), unpack);
  }

  if (has_errs)
  {
    m_py << tab << "try:" << endl;
    m_py << indent;
  }

  m_py << tab;
  if (!is_void)
  {
    m_py << "result = ";
  }
  m_py << "self." << name;
  m_py << join(params.begin(), params.end(), argument).left("(").right(")");
  m_py << endl;

  if (!is_void)
  {
    m_py << tab << "hermes.ReplyHeader.create(0x01, True).send(self.socket)" << endl;
    m_py << tab << "xdr = xdrlib.Packer()" << endl;
    translate(result)->pack(m_py, "result");
    m_py << tab << "self.socket.send(xdr.get_buffer())" << endl;
  }
  else
  {
    m_py << tab << "hermes.ReplyHeader.create(0x01, False).send(self.socket)" << endl;
  }

  if (has_errs)
  {
    m_py << unindent;
  }

  for (auto err : errors)
  {
    reply_id++;
    pointer type = translate(err);

    m_py << tab << "except " << type->name() << " as err:" << endl;
    m_py << indent;
    m_py << tab << "hermes.ReplyHeader.create(" << to_hex(reply_id) << ", True).send(self.socket)" << endl;
    m_py << tab << "xdr = xdrlib.Packer()" << endl;
    type->pack(m_py, "err");
    m_py << tab << "self.socket.send(xdr.get_buffer())" << endl;
    m_py << unindent;
  }

  m_py << unindent;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
