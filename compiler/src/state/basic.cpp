#include "state/basic.hpp"

namespace hermes {
namespace compiler {
namespace state {

basic::basic(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

bool
basic::is_basic() const
{
  return true;
}

void_t::void_t()
  : basic("void")
{
  // empty
}

bool
void_t::is_void() const
{
  return true;
}

bool_t::bool_t()
  : basic("bool")
{
  // empty
}

bool
bool_t::is_bool() const
{
  return true;
}

char_t::char_t()
  : basic("char")
{
  // empty
}

bool
char_t::is_char() const
{
  return true;
}

int8::int8()
  : basic("int8")
{
  // empty
}

bool
int8::is_int8() const
{
  return true;
}

int16::int16()
  : basic("int16")
{
  // empty
}

bool
int16::is_int16() const
{
  return true;
}

int32::int32()
  : basic("int32")
{
  // empty
}

bool
int32::is_int32() const
{
  return true;
}

int64::int64()
  : basic("int64")
{
  // empty
}

bool
int64::is_int64() const
{
  return true;
}

uint8::uint8()
  : basic("uint8")
{
  // empty
}

bool
uint8::is_uint8() const
{
  return true;
}

uint16::uint16()
  : basic("uint16")
{
  // empty
}

bool
uint16::is_uint16() const
{
  return true;
}

uint32::uint32()
  : basic("uint32")
{
  // empty
}

bool
uint32::is_uint32() const
{
  return true;
}

uint64::uint64()
  : basic("uint64")
{
  // empty
}

bool
uint64::is_uint64() const
{
  return true;
}

real32::real32()
  : basic("real32")
{
  // empty
}

bool
real32::is_real32() const
{
  return true;
}

real64::real64()
  : basic("real64")
{
  // empty
}

bool
real64::is_real64() const
{
  return true;
}

string::string()
  : basic("string")
{
  // empty
}

bool
string::is_string() const
{
  return true;
}

} // state namespace
} // compiler namespace
} // hermes namespace
