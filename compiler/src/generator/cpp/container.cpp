#include "generator/cpp/container.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

container::container(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

pair::pair(pointer a_first_type, pointer a_second_type)
  : container(
      "std::pair<"
      + a_first_type->value_type()
      + ", "
      + a_second_type->value_type()
      + ">"
    )
  , m_first_type(a_first_type)
  , m_second_type(a_second_type)
{
  // empty
}

map::map(pointer a_key_type, pointer a_value_type)
  : container(
      "std::map<"
      + a_key_type->value_type()
      + ", "
      + a_value_type->value_type()
      + ">"
    )
  , m_key_type(a_key_type)
  , m_value_type(a_value_type)
{
  // empty
}

set::set(pointer a_key_type)
  : container("std::set<" + a_key_type->value_type() + ">")
  , m_key_type(a_key_type)
{
  // empty
}

vector::vector(pointer a_value_type)
  : container("std::vector<" + a_value_type->value_type() + ">")
  , m_value_type(a_value_type)
{
  // empty
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
