#include "generator/fortran/generator.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

generator::generator()
  : m_blueprint(nullptr)
{
  // empty
}

void
generator::open(const std::string& a_project, const std::string& a_directory)
{
  m_project = a_project;
  m_src_path = a_directory + "/" + a_project + ".f90";
  m_src.open(m_src_path);
  m_src << tabsize(2);
}

void
generator::write(const state::blueprint& a_blueprint)
{
  m_blueprint = &a_blueprint;
  write_header();
  write_structure_types();
  write_interface_types();
  write_structure_interfaces();
  write_interface_interfaces();
  write_contains();
  write_structure_constructors();
  write_structure_methods();
  write_client_methods();
  write_server_methods();
  write_footer();
  m_blueprint = nullptr;
}

void
generator::close()
{
  m_project.clear();
  m_src_path.clear();
  m_src.close();
}

void
generator::write_header()
{
  m_src << tab << "module " << m_project << indent << std::endl << std::endl;
  m_src << tab << "use, intrinsic :: iso_c_binding" << std::endl;
  m_src << tab << "use :: hermes" << std::endl;
  m_src << tab << "use :: uint" << std::endl;
  m_src << tab << "use :: zmq" << std::endl;
  m_src << tab << "implicit none" << std::endl;
  m_src << tab << "private" << std::endl << std::endl;
}

void
generator::write_structure_types()
{
  using namespace std::placeholders;
  auto structs = m_blueprint->structures();
  auto excepts = m_blueprint->exceptions();
  auto write_structure_type = std::bind(&generator::structure_type, this, _1);

  std::for_each(structs.begin(), structs.end(), write_structure_type);
  std::for_each(excepts.begin(), excepts.end(), write_structure_type);
}

void
generator::write_interface_types()
{
  using namespace std::placeholders;
  auto ifaces = m_blueprint->interfaces();
  auto write_client_type = std::bind(&generator::client_type, this, _1);
  auto write_server_type = std::bind(&generator::server_type, this, _1);

  std::for_each(ifaces.begin(), ifaces.end(), write_client_type);
  std::for_each(ifaces.begin(), ifaces.end(), write_server_type);
}

void
generator::write_structure_interfaces()
{
  using namespace std::placeholders;
  auto structs = m_blueprint->structures();
  auto excepts = m_blueprint->exceptions();
  auto write_interface = std::bind(&generator::structure_interface, this, _1);

  std::for_each(structs.begin(), structs.end(), write_interface);
  std::for_each(excepts.begin(), excepts.end(), write_interface);
}

void
generator::write_interface_interfaces()
{
  using namespace std::placeholders;
  auto ifaces = m_blueprint->interfaces();
  auto write_interface = std::bind(&generator::server_interfaces, this, _1);

  m_src << tab << "interface" << std::endl << std::endl << indent;
  std::for_each(ifaces.begin(), ifaces.end(), write_interface);
  m_src << unindent << tab << "end interface" << std::endl << std::endl;
}

void
generator::write_contains()
{
  m_src << unindent << "contains" << indent << std::endl << std::endl;
}

void
generator::write_structure_constructors()
{
  using namespace std::placeholders;
  auto structs = m_blueprint->structures();
  auto excepts = m_blueprint->exceptions();
  auto write_constructor = std::bind(&generator::constructor, this, _1);

  std::for_each(structs.begin(), structs.end(), write_constructor);
  std::for_each(excepts.begin(), excepts.end(), write_constructor);
}

void
generator::write_structure_methods()
{
  using namespace std::placeholders;
  auto structs = m_blueprint->structures();
  auto excepts = m_blueprint->exceptions();
  auto write_methods = std::bind(&generator::structure_procedures, this, _1);

  std::for_each(structs.begin(), structs.end(), write_methods);
  std::for_each(excepts.begin(), excepts.end(), write_methods);
}

void
generator::write_client_methods()
{
  using namespace std::placeholders;
  auto ifaces = m_blueprint->interfaces();
  auto write_interface = std::bind(&generator::client_methods, this, _1);

  std::for_each(ifaces.begin(), ifaces.end(), write_interface);
}

void
generator::write_server_methods()
{
  using namespace std::placeholders;
  auto ifaces = m_blueprint->interfaces();
  auto write_interface = std::bind(&generator::server_methods, this, _1);

  std::for_each(ifaces.begin(), ifaces.end(), write_interface);
}

void
generator::write_footer()
{
  m_src << unindent << tab << "end module" << std::endl;
}

void
generator::structure_type(std::shared_ptr<state::structure> a_structure)
{
  using state::field;
  auto name = a_structure->name();
  auto fields = a_structure->fields();

  m_src << tab << "type, public, extends(serializable) :: ";
  m_src << name << std::endl;
  m_src << indent << indent;
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map())
    {
      auto as_map = std::dynamic_pointer_cast<state::map>(field_.type());
      auto key_type = translate(as_map->key_type());
      auto value_type = translate(as_map->value_type());
      m_src << tab << key_type->member() << ", dimension(:), allocatable, private :: " << member(field_.name()) << "_k" << std::endl;
      m_src << tab << value_type->member() << ", dimension(:), allocatable, private :: " << member(field_.name()) << "_v" << std::endl;
    }
    else
    {
      private_member(field_);
    }
  }
  m_src << unindent;
  m_src << tab << "contains" << std::endl;
  m_src << indent;
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_set())
    {
      public_procedure(name, "count_" + field_.name());
    }
    else
    {
      public_procedure(name, "get_" + field_.name());
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map() || field_.type()->is_set())
    {
      public_procedure(name, "insert_" + field_.name());
    }
    else
    {
      public_procedure(name, "set_" + field_.name());
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map() ||
        field_.type()->is_set() ||
        field_.type()->is_vector())
    {
      public_procedure(name, "size_" + field_.name());
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_vector())
    {
      public_procedure(name, "resize_" + field_.name());
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map() ||
        field_.type()->is_set() ||
        field_.type()->is_vector())
    {
      public_procedure(name, "clear_" + field_.name());
    }
  }
  m_src << std::endl;
  public_procedure(name, "read");
  public_procedure(name, "write");
  m_src << unindent << unindent;
  m_src << tab << "end type" << std::endl << std::endl;
}

void
generator::structure_interface(std::shared_ptr<state::structure> a_structure)
{
  const std::string name = a_structure->name();

  m_src << tab << "interface " << name << std::endl << indent;
  m_src << tab << "module procedure new_" << name << std::endl << unindent;
  m_src << tab << "end interface" << std::endl << std::endl;
}

void
generator::structure_procedures(std::shared_ptr<state::structure> a_structure)
{
  using state::field;
  auto name = a_structure->name();
  auto fields = a_structure->fields();

  for (const auto& field_ : fields)
  {
    setter(name, field_);
  }
  for (const auto& field_ : fields)
  {
    getter(name, field_);
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map() ||
        field_.type()->is_set() ||
        field_.type()->is_vector())
    {
      size(name, field_);
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_vector())
    {
      resizer(name, field_);
    }
  }
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map() ||
        field_.type()->is_set() ||
        field_.type()->is_vector())
    {
      clearer(name, field_);
    }
  }
  reader(a_structure);
  writer(a_structure);
}

void
generator::client_type(const state::interface& a_interface)
{
  using std::shared_ptr;
  using state::procedure;
  using state::exception;
  typedef shared_ptr<exception> ptr;

  auto name = a_interface.name();
  auto procedures = a_interface.procedures();
  auto excepts = a_interface.exceptions();

  auto first = true;
  auto prefix = name + "_client";
  auto catch_prefix = name + "_client_catch_";

  auto sep = [&](){ if (first) { first = false; return ""; }; return ", "; };
  auto pub = [&](const std::string& s) { public_procedure(prefix, s); };
  auto prv = [&](const std::string& s) { private_procedure(prefix, s); };
  auto rpc_base = [&](const procedure& p){ pub(p.name()); };
  auto rpc_code = [&](const procedure& p){ pub(p.name() + "_code"); };
  auto requestor = [&](const procedure& p){ prv("request_" + p.name()); };
  auto caught = [&](ptr e){ m_src << sep() << catch_prefix << e->name(); };
  auto catcher = [&](ptr e){ private_procedure(catch_prefix + e->name()); };

  m_src << tab << "type, public, extends(client) :: " << prefix << std::endl;
  m_src << indent << tab << "contains" << std::endl << indent;
  std::for_each(procedures.begin(), procedures.end(), rpc_base);
  m_src << std::endl;
  std::for_each(procedures.begin(), procedures.end(), rpc_code);
  m_src << std::endl;
  std::for_each(procedures.begin(), procedures.end(), requestor);
  m_src << std::endl;
  if (!excepts.empty())
  {
    m_src << tab << "generic, public :: catch => ";
    std::for_each(excepts.begin(), excepts.end(), caught);
    m_src << std::endl;
  }
  std::for_each(excepts.begin(), excepts.end(), catcher);
  m_src << unindent << unindent << tab << "end type" << std::endl << std::endl;
}

void
generator::client_methods(const state::interface& a_interface)
{
  using std::shared_ptr;
  using state::exception;
  using state::procedure;
  using namespace std::placeholders;

  auto id = 1;
  auto name = a_interface.name();
  auto procedures = a_interface.procedures();
  auto exceptions = a_interface.exceptions();
  auto write_base_call = std::bind(&generator::base_call, this, name, _1);
  auto write_code_call = std::bind(&generator::code_call, this, name, _1);
  auto write_request = [&](const procedure& p){ client_request(name, p, id); id++; };
  auto write_catcher = [&](const shared_ptr<exception> e){ client_catcher(name, e, id); id++; };

  std::for_each(procedures.begin(), procedures.end(), write_base_call);
  std::for_each(procedures.begin(), procedures.end(), write_code_call);
  std::for_each(procedures.begin(), procedures.end(), write_request);
  id = 2;
  std::for_each(exceptions.begin(), exceptions.end(), write_catcher);
}

void
generator::server_type(const state::interface& a_interface)
{
  using std::shared_ptr;
  using state::exception;
  using state::procedure;
  typedef shared_ptr<exception> ptr;

  auto procedures = a_interface.procedures();
  auto excepts = a_interface.exceptions();

  const std::string name = a_interface.name();
  const std::string prefix = a_interface.name() + "_server";
  const std::string throw_prefix = a_interface.name() + "_server_throw_";
  const std::string throw_error = throw_prefix + "error";

  auto def = [&](const std::string& s){ deferred_procedure(prefix, s); };
  auto prv = [&](const std::string& s){ private_procedure(prefix, s); };
  auto deferred = [&](const procedure& p){ def(p.name()); };
  auto handler = [&](const procedure& p){ prv("handle_" + p.name()); };
  auto requestor = [&](const procedure& p){ prv("request_" + p.name()); };
  auto thrown = [&](ptr e){ m_src << ", " << throw_prefix << e->name(); };
  auto thrower = [&](ptr e){ private_procedure(throw_prefix + e->name()); };

  m_src << tab << "type, public, abstract, extends(server) :: " << prefix << std::endl;
  m_src << indent << tab << "contains" << std::endl << indent;
  std::for_each(procedures.begin(), procedures.end(), deferred);
  m_src << std::endl;
  std::for_each(procedures.begin(), procedures.end(), handler);
  m_src << std::endl;
  std::for_each(procedures.begin(), procedures.end(), requestor);
  m_src << std::endl;

  m_src << tab << "generic, public :: throw => " << throw_error;
  std::for_each(excepts.begin(), excepts.end(), thrown);
  m_src << std::endl;
  m_src << tab << "procedure, private :: " << throw_error << std::endl;
  std::for_each(excepts.begin(), excepts.end(), thrower);
  m_src << std::endl;

  m_src << tab << "procedure, public :: serve_once => ";
  m_src << prefix << "_serve_once" << std::endl;
  m_src << unindent << unindent << tab << "end type" << std::endl << std::endl;
}

void
generator::server_interfaces(const state::interface& a_interface)
{
  using namespace std::placeholders;
  std::string name = a_interface.name();
  auto p = a_interface.procedures();
  auto fn = std::bind(&generator::server_interface, this, std::ref(name), _1);

  std::for_each(p.begin(), p.end(), fn);
}

void
generator::server_interface(const std::string& a_interface,
                            const state::procedure& a_procedure)
{
  using state::field;

  pointer type;
  auto name = a_procedure.name();
  auto result = a_procedure.result();
  auto params = a_procedure.parameters();
  auto used_structs = imports(result, params);
  auto used_symbols = symbols(result, params);
  bool first = true;
  bool is_void = result->is_void();
  bool is_string = result->is_string();

  auto ctype = a_interface + "_server";
  auto fname = a_interface + "_server_" + name;
  auto ftype = (is_void || is_string) ? "subroutine" : "function";

  auto sep = [&](){ if (!first) return ", "; first = false; return ": "; };
  auto args = [&](const field& f){ m_src << ", " << param(f.name()); };
  auto isos = [&](const std::string& s){ m_src << sep() << s; };
  auto imps = [&](const std::string& s){ m_src << tab << "import " << s << std::endl; };

  m_src << tab << ftype << " " << fname << "(self";
  std::for_each(params.begin(), params.end(), args);
  if (is_string)
  {
    m_src << ", r";
  }
  else if (!is_void)
  {
    m_src << ") result(r";
  }
  m_src << ")" << std::endl << indent;

  if (!used_symbols.empty())
  {
    first = true;
    m_src << tab << "use, intrinsic :: iso_c_binding, only ";
    std::for_each(used_symbols.begin(), used_symbols.end(), isos);
    m_src << std::endl;
  }

  m_src << tab << "import " << ctype << std::endl;
  std::for_each(used_structs.begin(), used_structs.end(), imps);

  m_src << tab << "class(" << ctype << ") :: self" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->in() << ", intent(in) :: ";
    m_src << param(f.name()) << std::endl;
  }

  if (is_string)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->out() << ", intent(out) :: r" << std::endl;
  }
  else if (!is_void)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->out() << " :: r" << std::endl;
  }

  m_src << unindent << tab << "end " << ftype << std::endl << std::endl;
}

void
generator::server_methods(const state::interface& a_interface)
{
  using std::shared_ptr;
  using state::exception;
  using state::procedure;
  using namespace std::placeholders;

  auto id = 2;
  auto name = a_interface.name();
  auto procedures = a_interface.procedures();
  auto excepts = a_interface.exceptions();

  auto write_handler = std::bind(&generator::server_handler, this, name, _1);
  auto write_request = std::bind(&generator::server_request, this, name, _1);
  auto write_thrower = [&](shared_ptr<exception> e){ server_throw(name, e, id); id++; };

  std::for_each(procedures.begin(), procedures.end(), write_handler);
  std::for_each(procedures.begin(), procedures.end(), write_request);
  std::for_each(excepts.begin(), excepts.end(), write_thrower);
  server_throw_error(a_interface);
  server_serve_once(a_interface);
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

std::string
generator::category(std::shared_ptr<state::datatype> a_datatype, bool a_input) const
{
  if (a_datatype->is_unsigned())
  {
    return "unsigned";
  }
  else if (a_datatype->is_char())
  {
    return "character";
  }
  else if (a_datatype->is_string())
  {
    if (a_input)
    {
      return "string";
    }
    else
    {
      return "value";
    }
  }
  else if (a_datatype->is_set())
  {
    auto as_set = std::dynamic_pointer_cast<state::set>(a_datatype);
    auto key_type = as_set->key_type();
    if (key_type->is_unsigned())
    {
      return "unsigned_vector";
    }
    else if (key_type->is_char())
    {
      return "character_vector";
    }
    else
    {
      return "vector";
    }
  }
  else if (a_datatype->is_vector())
  {
    auto as_vector = std::dynamic_pointer_cast<state::vector>(a_datatype);
    auto value_type = as_vector->value_type();
    if (value_type->is_unsigned())
    {
      return "unsigned_vector";
    }
    else if (value_type->is_char())
    {
      return "character_vector";
    }
    else
    {
      return "vector";
    }
  }
  return "value";
}

void
generator::public_procedure(const std::string& a_type, const std::string& a_name)
{
  m_src << tab << "procedure, public :: " << a_name;
  m_src << " => " << a_type << "_" << a_name << std::endl;
}

void
generator::private_procedure(const std::string& a_type, const std::string& a_name)
{
  m_src << tab << "procedure, private :: " << a_name;
  m_src << " => " << a_type << "_" << a_name << std::endl;
}

void
generator::private_procedure(const std::string& a_name)
{
  m_src << tab << "procedure, private :: " << a_name << std::endl;
}

void
generator::deferred_procedure(const std::string& a_type, const std::string& a_name)
{
  m_src << tab << "procedure(" << a_type << "_" << a_name << ")";
  m_src << ", public, deferred :: " << a_name << std::endl;
}

void
generator::private_member(const state::field& a_field)
{
  pointer field_type = translate(a_field.type());
  std::string type = field_type->member();
  std::string var = member(a_field.name());

  m_src << tab << type << ", private :: " << var << std::endl;
}

void
generator::private_member(const state::field& a_field, const std::string& a_suffix)
{
  pointer field_type = translate(a_field.type());
  std::string type = field_type->member();
  std::string var = member(a_field.name()) + a_suffix;

  m_src << tab << type << ", private :: " << var << std::endl;
}

void
generator::constructor(std::shared_ptr<state::structure> a_structure)
{
  using state::field;

  pointer type;
  bool first = true;
  auto name = a_structure->name();
  auto fields = a_structure->fields();
  std::string arg;
  std::string var;

  auto sep = [&](){ if (!first) return ", "; first = false; return ""; };

  m_src << tab << "function new_" << name << "(";
  for (const auto& field_ : fields)
  {
    if (field_.type()->is_map())
    {
      m_src << sep() << param(field_.name()) << "_k";
      m_src << sep() << param(field_.name()) << "_v";
    }
    else
    {
      m_src << sep() << param(field_.name());
    }
  }
  m_src << ") result(self)" << std::endl << indent;
  for (const auto& field_ : fields)
  {
    arg = param(field_.name());
    if (field_.type()->is_map())
    {
      auto as_map = std::dynamic_pointer_cast<state::map>(field_.type());
      auto key_type = translate(as_map->key_type());
      auto value_type = translate(as_map->value_type());
      m_src << tab << key_type->in() << ", dimension(:), intent(in) :: " << arg << "_k" << std::endl;
      m_src << tab << value_type->in() << ", dimension(:), intent(in) :: " << arg << "_v" << std::endl;
    }
    else
    {
      type = translate(field_.type());
      m_src << tab << type->in() << ", intent(in) :: " << arg << std::endl;
    }
  }
  m_src << tab << "type(" << name << ") :: self" << std::endl;
  m_src << std::endl;
  for (const auto& field_ : fields)
  {
    arg = param(field_.name());
    var = member(field_.name());
    if (field_.type()->is_string())
    {
      m_src << tab << "allocate(self%" << var << "(len(" << arg << ")))" << std::endl;
    }
    else if (field_.type()->is_map())
    {
      m_src << tab << "allocate(self%" << var << "_k(size(" << arg << "_k)))" << std::endl;
      m_src << tab << "allocate(self%" << var << "_v(size(" << arg << "_v)))" << std::endl;
    }
    else if (field_.type()->is_set() || field_.type()->is_vector())
    {
      m_src << tab << "allocate(self%" << var << "(size(" << arg << ")))" << std::endl;
    }
  }
  for (const auto& field_ : fields)
  {
    arg = param(field_.name());
    var = "self%" + member(field_.name());
    if (field_.type()->is_map())
    {
      m_src << tab << var << "_k = " << arg << "_k" << std::endl;
      m_src << tab << var << "_v = " << arg << "_v" << std::endl;
    }
    else
    {
      m_src << tab << var << " = " << arg << std::endl;
    }
  }
  m_src << unindent << tab << "end function" << std::endl << std::endl;
}

void
generator::getter(const std::string& a_structure, const state::field& a_field)
{
  std::string name = a_field.name();
  pointer type = translate(a_field.type());
  std::string arg = param(name);
  std::string var = "self%" + member(name);

  if (a_field.type()->is_map())
  {
    auto as_map = std::dynamic_pointer_cast<state::map>(a_field.type());
    auto key_type = translate(as_map->key_type());
    auto value_type = translate(as_map->value_type());
    m_src << tab << "function " << a_structure << "_get_" << name;
    m_src << "(self, " << arg << ") result(" << name << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << key_type->in() << ", intent(in) :: " << arg << std::endl;
    m_src << tab << value_type->out() << " :: " << name << std::endl;
    m_src << std::endl;
    m_src << unindent;
    m_src << tab << "end function" << std::endl << std::endl;
  }
  else if (a_field.type()->is_set())
  {
    auto as_set = std::dynamic_pointer_cast<state::set>(a_field.type());
    auto key_type = translate(as_set->key_type());
    m_src << tab << "function " << a_structure << "_count_" << name;
    m_src << "(self, " << arg << ") result(" << name << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << key_type->in() << " :: " << arg << std::endl;
    m_src << tab << "integer(kind = c_size_t) :: " << name << std::endl;
    m_src << std::endl;
    m_src << unindent;
    m_src << tab << "end function" << std::endl << std::endl;
  }
  else if (a_field.type()->is_vector())
  {
    auto as_vector = std::dynamic_pointer_cast<state::vector>(a_field.type());
    auto value_type = translate(as_vector->value_type());
    m_src << tab << "function " << a_structure << "_get_" << name;
    m_src << "(self, a_pos) result(" << name << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << "integer(kind = c_size_t), intent(in) :: a_pos" << std::endl;
    m_src << tab << value_type->out() << " :: " << name << std::endl;
    m_src << std::endl;
    m_src << tab << name << " = " << var << "(a_pos)" << std::endl;
    m_src << unindent;
    m_src << tab << "end function" << std::endl << std::endl;
  }
  else
  {
    m_src << tab << "function " << a_structure << "_get_" << name;
    m_src << "(self) result(" << name << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << type->out() << " :: " << name << std::endl;
    m_src << std::endl;
    m_src << tab << name << " = " << var << std::endl;
    m_src << unindent;
    m_src << tab << "end function" << std::endl << std::endl;
  }
}

void
generator::setter(const std::string& a_structure, const state::field& a_field)
{
  std::string name = a_field.name();
  pointer type = translate(a_field.type());
  std::string arg = param(name);
  std::string var = "self%" + member(name);

  if (a_field.type()->is_map())
  {
    auto as_map = std::dynamic_pointer_cast<state::map>(a_field.type());
    auto key_type = translate(as_map->key_type());
    auto value_type = translate(as_map->value_type());
    m_src << tab << "subroutine " << a_structure << "_insert_" << name;
    m_src << "(self, " << arg << "_k, " << arg << "_v)" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << key_type->in() << ", intent(in) :: " << arg << "_k" << std::endl;
    m_src << tab << value_type->in() << ", intent(in) :: " << arg << "_v" << std::endl;
    m_src << std::endl;
    m_src << unindent;
    m_src << tab << "end subroutine" << std::endl << std::endl;
  }
  else if (a_field.type()->is_set())
  {
    auto as_set = std::dynamic_pointer_cast<state::set>(a_field.type());
    auto key_type = translate(as_set->key_type());
    m_src << tab << "subroutine " << a_structure << "_insert_" << name;
    m_src << "(self, " << arg << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << key_type->in() << ", intent(in) :: " << arg << std::endl;
    m_src << std::endl;
    m_src << unindent;
    m_src << tab << "end subroutine" << std::endl << std::endl;
  }
  else if (a_field.type()->is_vector())
  {
    auto as_vector = std::dynamic_pointer_cast<state::vector>(a_field.type());
    auto value_type = translate(as_vector->value_type());
    m_src << tab << "subroutine " << a_structure << "_set_" << name;
    m_src << "(self, a_pos, " << arg << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << "integer(kind = c_size_t), intent(in) :: a_pos" << std::endl;
    m_src << tab << value_type->in() << ", intent(in) :: " << arg << std::endl;
    m_src << std::endl;
    m_src << tab << var << "(a_pos) = " << arg << std::endl;
    m_src << unindent;
    m_src << tab << "end subroutine" << std::endl << std::endl;
  }
  else
  {
    m_src << tab << "subroutine " << a_structure << "_set_" << name;
    m_src << "(self, " << arg << ")" << std::endl;
    m_src << indent;
    m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
    m_src << tab << type->out() << ", intent(in) :: " << arg << std::endl;
    m_src << std::endl;
    m_src << tab << var << " = " << arg << std::endl;
    m_src << unindent;
    m_src << tab << "end subroutine" << std::endl << std::endl;
  }
}

void
generator::size(const std::string& a_structure, const state::field& a_field)
{
  std::string name = a_field.name();
  std::string var = "self%" + member(name);

  if (a_field.type()->is_map())
  {
    var += "_k";
  }

  m_src << tab << "function " << a_structure << "_size_" << name;
  m_src << "(self) result(n)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
  m_src << tab << "integer(kind = c_size_t) :: n" << std::endl;
  m_src << std::endl;
  m_src << tab << "n = size(" << var << ")" << std::endl;
  m_src << unindent;
  m_src << tab << "end function" << std::endl << std::endl;
}

void
generator::resizer(const std::string& a_structure, const state::field& a_field)
{
  std::string name = a_field.name();
  std::string var = "self%" + member(name);

  m_src << tab << "subroutine " << a_structure << "_resize_" << name;
  m_src << "(self, a_size)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
  m_src << tab << "integer(kind = c_size_t), intent(in) :: a_size" << std::endl;
  m_src << std::endl;
  if (a_field.type()->is_map())
  {
    m_src << tab << "allocate(" << var << "_k(a_size))" << std::endl;
    m_src << tab << "allocate(" << var << "_v(a_size))" << std::endl;
  }
  else
  {
    m_src << tab << "allocate(" << var << "(a_size))" << std::endl;
  }
  m_src << unindent;
  m_src << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::clearer(const std::string& a_structure, const state::field& a_field)
{
  std::string name = a_field.name();
  std::string var = "self%" + member(name);

  m_src << tab << "subroutine " << a_structure << "_clear_" << name;
  m_src << "(self)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << a_structure << ") :: self" << std::endl;
  m_src << std::endl;
  if (a_field.type()->is_map())
  {
    m_src << tab << "deallocate(" << var << "_k)" << std::endl;
    m_src << tab << "deallocate(" << var << "_v)" << std::endl;
  }
  else
  {
    m_src << tab << "deallocate(" << var << ")" << std::endl;
  }
  m_src << unindent;
  m_src << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::reader(std::shared_ptr<state::structure> a_structure)
{
  std::string name = a_structure->name();

  m_src << tab << "function " << name << "_read(self, a_archive)";
  m_src << " result(status)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << name << ") :: self" << std::endl;
  m_src << tab << "type(iarchive), intent(inout) :: a_archive" << std::endl;
  m_src << tab << "logical :: status" << std::endl;
  m_src << std::endl;
  archive(a_structure->fields(), true);
  m_src << unindent;
  m_src << tab << "end function" << std::endl << std::endl;
}

void
generator::writer(std::shared_ptr<state::structure> a_structure)
{
  std::string name = a_structure->name();

  m_src << tab << "function " << name << "_write(self, a_archive)";
  m_src << " result(status)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << name << ") :: self" << std::endl;
  m_src << tab << "type(oarchive), intent(inout) :: a_archive" << std::endl;
  m_src << tab << "logical :: status" << std::endl;
  m_src << std::endl;
  archive(a_structure->fields(), false);
  m_src << unindent;
  m_src << tab << "end function" << std::endl << std::endl;
}

void
generator::archive(const field_vector& a_fields, bool a_input)
{
  bool first = true;
  for (const state::field& f : a_fields)
  {
    if (f.type()->is_map())
    {
      auto as_map = std::dynamic_pointer_cast<state::map>(f.type());
      auto key_type = std::make_shared<state::vector>(as_map->key_type());
      auto value_type = std::make_shared<state::vector>(as_map->value_type());
      archive(f.name() + "_k", key_type, a_input, first);
      archive(f.name() + "_v", value_type, a_input, false);
    }
    else
    {
      archive(f.name(), f.type(), a_input, first);
    }
    first = false;
  }
  m_src << std::endl;
}

void
generator::archive(const std::string& a_name,
                   std::shared_ptr<state::datatype> a_type,
                   bool a_input,
                   bool a_first)
{
  auto var = "self%" + member(a_name);
  auto method = "a_archive%" + category(a_type, a_input);
  if (a_first)
  {
    m_src << tab << "status = ";
  }
  else
  {
    m_src << " .and. &" << std::endl << tab << "         ";
  }
  m_src << method << "(" << var << ")";
}

void
generator::base_call(const std::string& a_interface,
                     const state::procedure& a_procedure)
{
  using state::field;

  pointer type;
  bool first = true;
  auto name = a_procedure.name();
  auto params = a_procedure.parameters();
  bool is_void = a_procedure.result()->is_void();
  bool is_string = a_procedure.result()->is_string();
  auto func_type = (is_void || is_string) ? "subroutine" : "function";
  auto func_name = a_interface + "_client_" + name;

  auto sep = [&](){ if (!first) return ", "; first = false; return ""; };
  auto args = [&](const field& f){ m_src << ", " << param(f.name()); };

  m_src << tab << func_type << " " << func_name << "(self";
  std::for_each(params.begin(), params.end(), args);
  if (is_string)
  {
    m_src << ", r";
  }
  else if (!is_void)
  {
    m_src << ") result(r";
  }
  m_src << ")" << std::endl << indent;

  m_src << tab << "class(" << a_interface << "_client) :: self" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->in() << ", intent(in) :: ";
    m_src << param(f.name()) << std::endl;
  }

  if (is_string)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->target() << ", intent(out) :: r" << std::endl;
  }
  else if (!is_void)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->target() << " :: r" << std::endl;
  }

  m_src << std::endl;
  m_src << tab << "integer(kind = c_int32_t) :: code" << std::endl << std::endl;
  m_src << tab << "code = self%" << name << "_code(";
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << sep() << param(f.name());
  }
  if (!is_void)
  {
    m_src << sep() << "r";
  }
  m_src << ")"<< std::endl;
  m_src << unindent << tab << "end " << func_type << std::endl << std::endl;
}

void
generator::code_call(const std::string& a_interface,
                     const state::procedure& a_procedure)
{
  using state::field;

  pointer type;
  int case_no = 2;
  bool first = true;
  auto name = a_procedure.name();
  auto params = a_procedure.parameters();
  auto result = a_procedure.result();
  bool is_void = a_procedure.result()->is_void();
  bool is_string = a_procedure.result()->is_string();
  auto func_name = a_interface + "_client_" + name + "_code";

  auto sep = [&](){ if (!first) return ", "; first = false; return ""; };
  auto args = [&](const field& f){ m_src << ", " << param(f.name()); };
  auto call_args = [&](const field& f){ m_src << sep() << param(f.name()); };

  m_src << tab << "function " << func_name << "(self";
  std::for_each(params.begin(), params.end(), args);
  if (!is_void)
  {
    m_src << ", r";
  }
  m_src << ") result(code)" << std::endl << indent;

  m_src << tab << "class(" << a_interface << "_client) :: self" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->in() << ", intent(in) :: ";
    m_src << param(f.name()) << std::endl;
  }
  if (is_string)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->target() << ", intent(out) :: r" << std::endl;
  }
  else if (!is_void)
  {
    type = translate(a_procedure.result());
    m_src << tab << type->target() << ", intent(out) :: r" << std::endl;
  }
  m_src << tab << "integer(kind = c_int32_t) :: code" << std::endl << std::endl;

  m_src << tab << "logical :: status" << std::endl;
  m_src << tab << "type(reply_header) :: header" << std::endl;
  if (!is_void && !is_string)
  {
    m_src << tab << "class(*), pointer :: ptr" << std::endl;
  }
  m_src << std::endl;

  m_src << tab << "call self%request_" << name << "(";
  std::for_each(params.begin(), params.end(), call_args);
  m_src << ")" << std::endl;
  m_src << tab << "header = self%get_header()" << std::endl;
  m_src << tab << "select case (header%number())" << std::endl;
  m_src << indent;
  m_src << tab << "case (1)" << std::endl;
  m_src << indent;
  m_src << tab << "code = 0" << std::endl;
  if (is_string)
  {
    m_src << tab << "call self%get_result_string(r)" << std::endl;
  }
  else if (!is_void)
  {
    m_src << tab << "ptr => r" << std::endl;
    m_src << tab << "call self%get_result_";
    m_src << category(result, true);
    m_src << "(ptr)" << std::endl;
  }
  m_src << unindent;

  for (auto ptr : a_procedure.exceptions())
  {
    m_src << tab << "case (" << case_no << ")" << std::endl;
    m_src << indent;
    m_src << tab << "code = -" << case_no << std::endl;
    m_src << tab << "call self%get_exception()" << std::endl;
    m_src << unindent;
    ++case_no;
  }

  m_src << tab << "case default" << std::endl;
  m_src << indent;
  m_src << tab << "code = -1" << std::endl;
  m_src << unindent;
  m_src << unindent;
  m_src << tab << "end select" << std::endl;

  m_src << unindent << tab << "end function" << std::endl << std::endl;
}

void
generator::client_request(const std::string& a_interface,
                          const state::procedure& a_procedure,
                          int a_id)
{
  using state::field;

  pointer type;
  auto first = true;
  auto name = a_procedure.name();
  auto result = a_procedure.result();
  auto params = a_procedure.parameters();
  auto has_args = !params.empty();
  auto is_void = result->is_void();
  auto func_name = a_interface + "_client_request_" + name;

  auto args = [&](const field& f){ m_src << ", " << param(f.name()); };

  m_src << tab << "subroutine " << func_name << "(self";
  std::for_each(params.begin(), params.end(), args);
  m_src << ")" << std::endl << indent;

  m_src << tab << "class(" << a_interface << "_client) :: self" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->in() << ", intent(in) :: ";
    m_src << param(f.name()) << std::endl;
  }
  m_src << std::endl;
  m_src << tab << "logical :: status" << std::endl;
  m_src << tab << "type(request_header) :: header" << std::endl;
  if (has_args)
  {
    m_src << tab << "type(oarchive) :: archive" << std::endl;
    m_src << tab << "type(zmq_msg_t) :: message" << std::endl;
    m_src << tab << "integer(kind = c_int) :: code" << std::endl;
    m_src << tab << "integer(kind = c_size_t) :: archive_size" << std::endl;
    m_src << tab << "character(kind = c_char, len = :), pointer :: buffer" << std::endl;
  }
  m_src << std::endl;

  if (has_args)
  {
    m_src << tab << sizevar("archive_size", get_size(params));
    m_src << tab << "code = zmq_msg_init_size(message, archive_size)" << std::endl;
    m_src << tab << "call c_f_pointer(zmq_msg_data(message), buffer)" << std::endl;
    m_src << tab << "call archive%create(buffer, archive_size)" << std::endl;
    m_src << tab << "status = ";
    for (const field& f : params)
    {
      m_src << (first ? "" : " .and. ");
      m_src << "archive%" << category(f.type(), false);
      m_src << "(" << param(f.name()) << ")";
      first = false;
    }
    m_src << std::endl;
  }
  m_src << tab << "status = header%send(self%socket, " << a_id << ", ";
  m_src << (is_void ? ".false." : ".true.") << ")" << std::endl;
  if (has_args)
  {
    m_src << tab << "code = zmq_msg_send(message, self%socket, 0)" << std::endl;
  }

  m_src << unindent << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::client_catcher(const std::string& a_interface,
                          std::shared_ptr<state::exception> a_exception,
                          int a_id)
{
  auto name = a_exception->name();
  auto cname = a_interface + "_client";
  auto fname = a_interface + "_client_catch_" + name;

  m_src << tab << "subroutine " << fname << "(self, a_exception)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << cname << ") :: self" << std::endl;
  m_src << tab << "type(" << name << "), target, intent(inout) :: a_exception" << std::endl << std::endl;
  m_src << tab << "class(serializable), pointer :: exception" << std::endl << std::endl;
  m_src << tab << "exception => a_exception" << std::endl;
  m_src << tab << "call self%catch_exception(" << a_id << ", exception)" << std::endl;
  m_src << unindent;
  m_src << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::server_handler(const std::string& a_interface,
                          const state::procedure& a_procedure)
{
  using state::field;

  pointer type;
  auto id = 2;
  auto name = a_procedure.name();
  auto result = a_procedure.result();
  auto params = a_procedure.parameters();
  auto excepts = a_procedure.exceptions();
  auto result_type = translate(result);
  auto cname = a_interface + "_server";
  auto fname = a_interface + "_server_handle_" + name;
  auto first = true;
  auto is_void = result->is_void();
  auto is_string = result->is_string();
  auto is_call = is_void || is_string;

  auto sep = [&](){ if (!first) return ", "; first = false; return ""; };
  auto args = [&](const field& f){ m_src << sep() << param(f.name()); };

  m_src << tab << "subroutine " << fname << "(self)" << std::endl << indent;
  m_src << tab << "class(" << cname << ") :: self" << std::endl << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->out() << " :: " << param(f.name()) << std::endl;
  }
  if (!is_void)
  {
    m_src << tab << "integer(kind = c_size_t) :: size" << std::endl;
    m_src << tab << result_type->target() << " :: r" << std::endl;
    m_src << tab << "class(*), pointer :: ptr" << std::endl;
  }
  if (!params.empty())
  {
    m_src << std::endl;
  }

  if (!is_void)
  {
    first = true;
    m_src << tab << "call self%request_" << name << "(";
    std::for_each(params.begin(), params.end(), args);
    m_src << ")" << std::endl;
  }

  first = true;
  m_src << tab << (is_call ? "call" : "r =") << " self%" << name << "(";
  std::for_each(params.begin(), params.end(), args);
  m_src << (is_string ? ", r" : "") << ")" << std::endl;

  m_src << tab << "select case (self%outcome())" << std::endl << indent;
  m_src << tab << "case (1)" << std::endl << indent;
  m_src << tab << "call self%reply_with_error()" << std::endl << unindent;
  for (auto e : excepts)
  {
    m_src << tab << "case (" << id << ")" << std::endl << indent;
    m_src << tab << "call self%reply_with_exception(" << id << ")" << std::endl << unindent;
    id++;
  }
  m_src << tab << "case default" << std::endl << indent;
  if (is_void)
  {
    m_src << tab << "call self%reply_with_void()" << std::endl;
  }
  else
  {
    m_src << tab << sizevar("size", get_size("r", result_type));
    m_src << tab << "ptr => r" << std::endl;
    m_src << tab << "call self%reply_with_result_";
    m_src << category(result, false) << "(ptr, size)" << std::endl;
  }
  m_src << unindent << unindent << tab << "end select" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    if (type->allocatable())
    {
      m_src << tab << "deallocate(" << param(f.name()) << ")" << std::endl;
    }
  }
  if (result_type && result_type->allocatable())
  {
    m_src << tab << "deallocate(r)" << std::endl;
  }

  m_src << unindent << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::server_request(const std::string& a_interface,
                          const state::procedure& a_procedure)
{
  using state::field;

  pointer type;
  auto name = a_procedure.name();
  auto params = a_procedure.parameters();
  auto cname = a_interface + "_server";
  auto fname = a_interface + "_server_request_" + name;

  auto args = [&](const field& f){ m_src << ", " << param(f.name()); };

  m_src << tab << "subroutine " << fname << "(self";
  std::for_each(params.begin(), params.end(), args);
  m_src << ")" << std::endl << indent;

  m_src << tab << "class(" << cname << ") :: self" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    m_src << tab << type->out() << ", intent(out) :: " << param(f.name()) << std::endl;
  }
  m_src << std::endl;
  m_src << tab << "logical :: status" << std::endl;
  m_src << tab << "type(iarchive) :: archive" << std::endl;
  m_src << tab << "type(zmq_msg_t) :: message" << std::endl;
  m_src << tab << "integer(kind = c_int) :: code" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    if (type->allocatable() && !f.type()->is_string())
    {
      m_src << tab << "integer(kind = c_int32_t) :: length" << std::endl;
      break;
    }
  }
  m_src << std::endl;

  m_src << tab << "code = zmq_msg_init(message)" << std::endl;
  m_src << tab << "code = zmq_msg_recv(message, self%socket, 0)" << std::endl;
  m_src << tab << "call archive%create(zmq_msg_data(message), zmq_msg_size(message))" << std::endl;
  for (const auto& f : params)
  {
    type = translate(f.type());
    if (type->allocatable() && !f.type()->is_string())
    {
      m_src << tab << "status = archive%length(length)" << std::endl;
      m_src << tab << "allocate(" << param(f.name()) << "(length))" << std::endl;
    }
    m_src << tab << "status = archive%" << category(f.type(), true);
    m_src << "(" << param(f.name()) << ")" << std::endl;
  }
  m_src << tab << "code = zmq_msg_close(message)" << std::endl;

  m_src << unindent << tab << "end subroutine" << std::endl << std::endl;
}

void
generator::server_throw(const std::string& a_interface,
                        std::shared_ptr<state::exception> a_exception,
                        int a_id)
{
  auto name = a_exception->name();
  auto cname = a_interface + "_server";
  auto fname = a_interface + "_server_throw_" + name;
  auto type = translate(a_exception);

  m_src << tab << "subroutine " << fname << "(self, a_exception)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << cname << ") :: self" << std::endl;
  m_src << tab << "type(" << name << "), pointer, intent(in) :: a_exception" << std::endl;
  m_src << std::endl;
  m_src << tab << "integer(kind = c_size_t) :: size" << std::endl << std::endl;
  m_src << tab << sizevar("size", get_size("a_exception", type));
  m_src << tab << "call self%throw_exception(a_exception, " << a_id << ", size)" << std::endl;
  m_src << unindent;
  m_src << tab << "end subroutine" << std::endl;
}

void
generator::server_throw_error(const state::interface& a_interface)
{
  using std::endl;

  auto name = a_interface.name();
  auto cname = name + "_server";
  auto fname = cname + "_throw_error";

  m_src << tab << "subroutine " << fname << "(self)" << endl << indent;
  m_src << tab << "class(" << cname << ") :: self" << endl << endl;
  m_src << tab << "call self%throw_error()" << endl;
  m_src << unindent << tab << "end subroutine" << endl << endl;
}

void
generator::server_serve_once(const state::interface& a_interface)
{
  auto id = 1;
  auto name = a_interface.name();
  auto procedures = a_interface.procedures();

  m_src << tab << "subroutine " << name << "_server_serve_once(self)" << std::endl;
  m_src << indent;
  m_src << tab << "class(" << name << "_server) :: self" << std::endl << std::endl;
  m_src << tab << "type(request_header) :: header" << std::endl << std::endl;
  m_src << tab << "header = self%get_request()" << std::endl;
  m_src << tab << "select case (header%number())" << std::endl;
  m_src << indent;
  for (const auto& p : procedures)
  {
    m_src << tab << "case (" << id << ")" << std::endl;
    m_src << indent;
    m_src << tab << "call self%handle_" << p.name() << "()" << std::endl;
    m_src << unindent;
    id++;
  }
  m_src << tab << "case default" << std::endl << indent;
  m_src << tab << "call self%undefined(header)" << std::endl;
  m_src << unindent << unindent;
  m_src << tab << "end select" << std::endl << unindent;
  m_src << tab << "end subroutine" << std::endl << std::endl;
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

std::set<std::string>
generator::imports(std::shared_ptr<state::datatype> a_type) const
{
  pointer type = translate(a_type);
  if (!type)
  {
    return { };
  }
  return type->structures();
}

std::set<std::string>
generator::imports(std::shared_ptr<state::datatype> a_result,
                   const field_vector& a_fields) const
{
  std::set<std::string> all_imports = imports(a_result);
  std::set<std::string> field_imports;
  for (const state::field& the_field : a_fields)
  {
    auto field_imports = imports(the_field.type());
    all_imports.insert(field_imports.begin(), field_imports.end());
  }
  return all_imports;
}

std::set<std::string>
generator::symbols(std::shared_ptr<state::datatype> a_type) const
{
  pointer type = translate(a_type);
  if (!type)
  {
    return { };
  }
  return type->iso_c_symbols();
}

std::set<std::string>
generator::symbols(std::shared_ptr<state::datatype> a_result,
                   const field_vector& a_fields) const
{
  std::set<std::string> all_symbols = symbols(a_result);
  std::set<std::string> field_symbols;
  for (const state::field& the_field : a_fields)
  {
    auto field_symbols = symbols(the_field.type());
    all_symbols.insert(field_symbols.begin(), field_symbols.end());
  }
  return all_symbols;
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
