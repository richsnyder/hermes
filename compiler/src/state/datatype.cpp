#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

datatype::datatype(const std::string& a_name)
  : m_name(a_name)
{
  // empty
}

std::string
datatype::name() const
{
  return m_name;
}

bool
datatype::is_alias() const
{
  return false;
}

bool
datatype::is_basic() const
{
  return false;
}

bool
datatype::is_container() const
{
  return false;
}

bool
datatype::is_enumeration() const
{
  return false;
}

bool
datatype::is_exception() const
{
  return false;
}

bool
datatype::is_structure() const
{
  return false;
}

bool
datatype::is_bool() const
{
  return false;
}

bool
datatype::is_char() const
{
  return false;
}

bool
datatype::is_int8() const
{
  return false;
}

bool
datatype::is_int16() const
{
  return false;
}

bool
datatype::is_int32() const
{
  return false;
}

bool
datatype::is_int64() const
{
  return false;
}

bool
datatype::is_uint8() const
{
  return false;
}

bool
datatype::is_uint16() const
{
  return false;
}

bool
datatype::is_uint32() const
{
  return false;
}

bool
datatype::is_uint64() const
{
  return false;
}

bool
datatype::is_real32() const
{
  return false;
}

bool
datatype::is_real64() const
{
  return false;
}

bool
datatype::is_string() const
{
  return false;
}

bool
datatype::is_void() const
{
  return false;
}

bool
datatype::is_map() const
{
  return false;
}

bool
datatype::is_set() const
{
  return false;
}

bool
datatype::is_vector() const
{
  return false;
}

bool
datatype::is_signed() const
{
  return is_int8() || is_int16() || is_int32() || is_int64();
}

bool
datatype::is_unsigned() const
{
  return is_uint8() || is_uint16() || is_uint32() || is_uint64();
}

bool
datatype::is_real() const
{
  return is_real32() || is_real64();
}

} // state namespace
} // compiler namespace
} // hermes namespace
