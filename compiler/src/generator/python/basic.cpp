#include "generator/python/basic.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

basic::basic(const std::string& a_name,
             const std::string& a_xdr_type,
             const std::string& a_numpy_type)
  : datatype(a_name, a_numpy_type)
  , m_xdr_type(a_xdr_type)
{
  // empty
}

void
basic::pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy) const
{
  a_out << tab << "xdr.pack_" << m_xdr_type
        << "(" << a_variable << ")" << std::endl;
}

void
basic::unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy) const
{
  a_out << tab << a_variable << " = xdr.unpack_" << m_xdr_type
        << "()" << std::endl;
}

bool_t::bool_t()
  : basic("bool", "bool", "bool_")
{
  // empty
}

std::string
bool_t::default_value() const
{
  return "False";
}

char_t::char_t()
  : basic("str", "fstring", "string_")
{
  // empty
}

std::string
char_t::default_value() const
{
  return "' '";
}

void
char_t::pack(std::ostream& a_out,
             const std::string& a_variable,
             bool a_numpy) const
{
  a_out << tab << "xdr.pack_fstring(" << a_variable << ", 1)" << std::endl;
}

void
char_t::unpack(std::ostream& a_out,
               const std::string& a_variable,
               bool a_numpy) const
{
  a_out << tab << a_variable << " = xdr.unpack_fstring(1)" << std::endl;
}

int8::int8()
  : basic("int", "int", "int8")
{
  // empty
}

std::string
int8::default_value() const
{
  return "0";
}

int16::int16()
  : basic("int", "int", "int16")
{
  // empty
}

std::string
int16::default_value() const
{
  return "0";
}

int32::int32()
  : basic("int", "int", "int32")
{
  // empty
}

std::string
int32::default_value() const
{
  return "0";
}

int64::int64()
  : basic("long", "hyper", "int64")
{
  // empty
}

std::string
int64::default_value() const
{
  return "0";
}

uint8::uint8()
  : basic("int", "uint", "uint8")
{
  // empty
}

std::string
uint8::default_value() const
{
  return "0";
}

uint16::uint16()
  : basic("int", "uint", "uint16")
{
  // empty
}

std::string
uint16::default_value() const
{
  return "0";
}

uint32::uint32()
  : basic("long", "uint", "uint32")
{
  // empty
}

std::string
uint32::default_value() const
{
  return "0";
}

uint64::uint64()
  : basic("long", "uhyper", "uint64")
{
  // empty
}

std::string
uint64::default_value() const
{
  return "0";
}

real32::real32()
  : basic("float", "float", "float32")
{
  // empty
}

std::string
real32::default_value() const
{
  return "0.0";
}

real64::real64()
  : basic("float", "double", "float64")
{
  // empty
}

std::string
real64::default_value() const
{
  return "0.0";
}

string::string()
  : basic("str", "string", "string_")
{
  // empty
}

std::string
string::default_value() const
{
  return "''";
}

void
string::pack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << "hermes.xdr_pack_string(xdr, " << a_variable << ")" << std::endl;
}

void
string::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << a_variable << " = hermes.xdr_unpack_string(xdr)" << std::endl;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
