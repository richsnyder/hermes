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

std::shared_ptr<sizer>
void_t::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 0);
}

bool_t::bool_t()
  : basic("bool")
{
  // empty
}

std::shared_ptr<sizer>
bool_t::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

char_t::char_t()
  : basic("char")
{
  // empty
}

std::shared_ptr<sizer>
char_t::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

int8::int8()
  : basic("std::int8_t")
{
  // empty
}

std::shared_ptr<sizer>
int8::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

int16::int16()
  : basic("std::int16_t")
{
  // empty
}

std::shared_ptr<sizer>
int16::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

int32::int32()
  : basic("std::int32_t")
{
  // empty
}

std::shared_ptr<sizer>
int32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

int64::int64()
  : basic("std::int64_t")
{
  // empty
}

std::shared_ptr<sizer>
int64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
}

uint8::uint8()
  : basic("std::uint8_t")
{
  // empty
}

std::shared_ptr<sizer>
uint8::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

uint16::uint16()
  : basic("std::uint16_t")
{
  // empty
}

std::shared_ptr<sizer>
uint16::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

uint32::uint32()
  : basic("std::uint32_t")
{
  // empty
}

std::shared_ptr<sizer>
uint32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

uint64::uint64()
  : basic("std::uint64_t")
{
  // empty
}

std::shared_ptr<sizer>
uint64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
}

real32::real32()
  : basic("float")
{
  // empty
}

std::shared_ptr<sizer>
real32::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

real64::real64()
  : basic("double")
{
  // empty
}

std::shared_ptr<sizer>
real64::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 8);
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

std::shared_ptr<sizer>
string::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, "{}.size()", 1);
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
