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

std::shared_ptr<sizer>
bool_t::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
char_t::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
int8::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
int16::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
int32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
int64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
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

std::shared_ptr<sizer>
uint8::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
uint16::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
uint32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
}

std::string
uint64::in() const
{
  return "integer(kind = c_int64_t)";
}

std::shared_ptr<sizer>
uint64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
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

std::shared_ptr<sizer>
real32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
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

std::shared_ptr<sizer>
real64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
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

std::shared_ptr<sizer>
string::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, "len({})", 1);
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
