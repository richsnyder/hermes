#include "generator/cpp/basic.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

basic::basic(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

std::string
basic::param_type() const
{
  return "const " + name();
}

void_t::void_t()
  : basic("void")
{
  // empty
}

bool_t::bool_t()
  : basic("bool")
{
  // empty
}

char_t::char_t()
  : basic("char")
{
  // empty
}

int8::int8()
  : basic("std::int8_t")
{
  // empty
}

int16::int16()
  : basic("std::int16_t")
{
  // empty
}

int32::int32()
  : basic("std::int32_t")
{
  // empty
}

int64::int64()
  : basic("std::int64_t")
{
  // empty
}

uint8::uint8()
  : basic("std::uint8_t")
{
  // empty
}

uint16::uint16()
  : basic("std::uint16_t")
{
  // empty
}

uint32::uint32()
  : basic("std::uint32_t")
{
  // empty
}

uint64::uint64()
  : basic("std::uint64_t")
{
  // empty
}

real32::real32()
  : basic("float")
{
  // empty
}

real64::real64()
  : basic("double")
{
  // empty
}

string::string()
  : basic("std::string")
{
  // empty
}

std::string
string::param_type() const
{
  return "const " + name() + '&';
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
