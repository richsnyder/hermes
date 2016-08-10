#include "generator/python/container.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

container::container(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

map::map(pointer a_key_type, pointer a_value_type)
  : container("dict")
  , m_key_type(a_key_type)
  , m_value_type(a_value_type)
{
  // empty
}

std::string
map::default_value() const
{
  return "{}";
}

void
map::pack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  a_out << tab << "xdr.pack_uint(len(" << a_variable << "))" << endl;
  a_out << tab << "for key, value in " << a_variable << ".iteritems():" << endl;
  a_out << indent;
  m_key_type->pack(a_out, "key");
  m_value_type->pack(a_out, "value");
  a_out << unindent;
}

void
map::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  auto length = "l_" + a_variable;
  a_out << tab << a_variable << " = {}" << endl;
  a_out << tab << length << " = xdr.unpack_uint()" << endl;
  a_out << tab << "for n in range(" << length << "):" << endl;
  a_out << indent;
  m_key_type->unpack(a_out, "key");
  m_value_type->unpack(a_out, "value");
  a_out << tab << a_variable << "[key] = value" << endl;
  a_out << unindent;
}

set::set(pointer a_key_type)
  : container("set")
  , m_key_type(a_key_type)
{
  // empty
}

std::string
set::default_value() const
{
  return "set()";
}

void
set::pack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  a_out << tab << "xdr.pack_uint(len(" << a_variable << "))" << endl;
  a_out << tab << "for key in " << a_variable << ":" << endl;
  a_out << indent;
  m_key_type->pack(a_out, "key");
  a_out << unindent;
}

void
set::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  auto length = "l_" + a_variable;
  a_out << tab << a_variable << " = set()" << endl;
  a_out << tab << length << " = xdr.unpack_uint()" << endl;
  a_out << tab << "for n in range(" << length << "):" << endl;
  a_out << indent;
  m_key_type->unpack(a_out, "key");
  a_out << tab << a_variable << ".update([key])" << endl;
  a_out << unindent;
}

vector::vector(pointer a_value_type)
  : container("list")
  , m_value_type(a_value_type)
{
  // empty
}

std::string
vector::default_value() const
{
  return "[]";
}

void
vector::pack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  a_out << tab << "xdr.pack_uint(len(" << a_variable << "))" << endl;
  a_out << tab << "for value in " << a_variable << ":" << endl;
  a_out << indent;
  m_value_type->pack(a_out, "value");
  a_out << unindent;
}

void
vector::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  using std::endl;

  auto length = "l_" + a_variable;
  a_out << tab << a_variable << " = []" << endl;
  a_out << tab << length << " = xdr.unpack_uint()" << endl;
  a_out << tab << "for n in range(" << length << "):" << endl;
  a_out << indent;
  m_value_type->unpack(a_out, "value");
  a_out << tab << a_variable << ".append(value)" << endl;
  a_out << unindent;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
