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

std::shared_ptr<sizer>
pair::size(const std::string& a_variable) const
{
  std::string first_name = a_variable + ".first";
  std::string second_name = a_variable + ".second";
  std::shared_ptr<sizer> first_sizer = m_first_type->size(first_name);
  std::shared_ptr<sizer> second_sizer = m_second_type->size(second_name);
  first_sizer->link(second_sizer);
  return first_sizer;
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
