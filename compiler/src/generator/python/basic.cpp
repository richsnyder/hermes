#include "generator/python/basic.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

basic::basic(const std::string& a_name, const std::string& a_type)
  : datatype(a_name)
  , m_type(a_type)
{
  // empty
}

void
basic::pack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << "xdr.pack_" << m_type << "(" << a_variable << ")" << std::endl;
}

void
basic::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << a_variable << " = xdr.unpack_" << m_type << "()" << std::endl;
}

bool_t::bool_t()
  : basic("bool", "bool")
{
  // empty
}

std::string
bool_t::default_value() const
{
  return "False";
}

char_t::char_t()
  : basic("str", "fstring")
{
  // empty
}

std::string
char_t::default_value() const
{
  return "' '";
}

void
char_t::pack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << "xdr.pack_fstring(self." << a_variable << ", 1)" << std::endl;
}

void
char_t::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << "xdr.unpack_fstring(1)" << std::endl;
}

int8::int8()
  : basic("int", "int")
{
  // empty
}

std::string
int8::default_value() const
{
  return "0";
}

int16::int16()
  : basic("int", "int")
{
  // empty
}

std::string
int16::default_value() const
{
  return "0";
}

int32::int32()
  : basic("int", "int")
{
  // empty
}

std::string
int32::default_value() const
{
  return "0";
}

int64::int64()
  : basic("long", "hyper")
{
  // empty
}

std::string
int64::default_value() const
{
  return "0";
}

uint8::uint8()
  : basic("int", "uint")
{
  // empty
}

std::string
uint8::default_value() const
{
  return "0";
}

uint16::uint16()
  : basic("int", "uint")
{
  // empty
}

std::string
uint16::default_value() const
{
  return "0";
}

uint32::uint32()
  : basic("long", "uint")
{
  // empty
}

std::string
uint32::default_value() const
{
  return "0";
}

uint64::uint64()
  : basic("long", "uhyper")
{
  // empty
}

std::string
uint64::default_value() const
{
  return "0";
}

real32::real32()
  : basic("float", "float")
{
  // empty
}

std::string
real32::default_value() const
{
  return "0.0";
}

real64::real64()
  : basic("float", "double")
{
  // empty
}

std::string
real64::default_value() const
{
  return "0.0";
}

string::string()
  : basic("str", "string")
{
  // empty
}

std::string
string::default_value() const
{
  return "''";
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
