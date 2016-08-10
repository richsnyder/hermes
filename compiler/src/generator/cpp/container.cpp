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

std::shared_ptr<sizer>
map::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 0);
}


set::set(pointer a_key_type)
  : container("std::set<" + a_key_type->value_type() + ">")
  , m_key_type(a_key_type)
{
  // empty
}

std::shared_ptr<sizer>
set::size(const std::string& a_variable) const
{
  std::shared_ptr<sizer> key_sizer = m_key_type->size(a_variable);
  return std::make_shared<sizer>(a_variable, "{}.size()", key_sizer);
}

vector::vector(pointer a_value_type)
  : container("std::vector<" + a_value_type->value_type() + ">")
  , m_value_type(a_value_type)
{
  // empty
}

std::shared_ptr<sizer>
vector::size(const std::string& a_variable) const
{
  std::shared_ptr<sizer> value_sizer = m_value_type->size(a_variable);
  return std::make_shared<sizer>(a_variable, "{}.size()", value_sizer);
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
