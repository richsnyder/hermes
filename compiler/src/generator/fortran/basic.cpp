#include "generator/fortran/basic.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

std::string
bool_t::in() const
{
  return "logical";
}

std::string
char_t::in() const
{
  return "character(kind = c_char)";
}

std::set<std::string>
char_t::iso_c_symbols() const
{
  return { "c_char" };
}

std::string
int8::in() const
{
  return "integer(kind = c_int8_t)";
}

std::set<std::string>
int8::iso_c_symbols() const
{
  return { "c_int8_t" };
}

std::string
int16::in() const
{
  return "integer(kind = c_int16_t)";
}

std::set<std::string>
int16::iso_c_symbols() const
{
  return { "c_int16_t" };
}

std::string
int32::in() const
{
  return "integer(kind = c_int32_t)";
}

std::set<std::string>
int32::iso_c_symbols() const
{
  return { "c_int32_t" };
}

std::string
int64::in() const
{
  return "integer(kind = c_int64_t)";
}

std::set<std::string>
int64::iso_c_symbols() const
{
  return { "c_int64_t" };
}

std::string
uint8::in() const
{
  return "integer(kind = c_int16_t)";
}

std::set<std::string>
uint8::iso_c_symbols() const
{
  return { "c_int16_t" };
}

std::string
uint16::in() const
{
  return "integer(kind = c_int32_t)";
}

std::set<std::string>
uint16::iso_c_symbols() const
{
  return { "c_int32_t" };
}

std::string
uint32::in() const
{
  return "integer(kind = c_int64_t)";
}

std::set<std::string>
uint32::iso_c_symbols() const
{
  return { "c_int64_t" };
}

std::string
uint64::in() const
{
  return "integer(kind = c_int64_t)";
}

std::string
real32::in() const
{
  return "real(kind = c_float)";
}

std::set<std::string>
real32::iso_c_symbols() const
{
  return { "c_float" };
}

std::string
real64::in() const
{
  return "real(kind = c_double)";
}

std::set<std::string>
real64::iso_c_symbols() const
{
  return { "c_double" };
}

std::string
string::in() const
{
  return "character(kind = c_char, len = :), allocatable";
}

std::string
string::out() const
{
  return "character(kind = c_char, len = :), allocatable";
}

bool
string::allocatable() const
{
  return true;
}

std::set<std::string>
string::iso_c_symbols() const
{
  return { "c_char" };
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
