#include "state/enumeration.hpp"

namespace hermes {
namespace compiler {
namespace state {

enumeration::enumeration(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

bool
enumeration::is_enumeration() const
{
  return true;
}

const std::vector<enumeration::item>&
enumeration::items() const
{
  return m_items;
}

void
enumeration::add(const std::string& a_name, const item::value_type& a_value)
{
  m_items.emplace_back(a_name, a_value);
}

enumeration::item::item(const std::string& a_name, const value_type& a_value)
  : m_name(a_name)
  , m_value(a_value)
{
  // empty
}

std::string
enumeration::item::name() const
{
  return m_name;
}

enumeration::item::value_type
enumeration::item::value() const
{
  return m_value;
}

} // state namespace
} // compiler namespace
} // hermes namespace
