#include "state/space.hpp"

namespace hermes {
namespace compiler {
namespace state {

space::space(const std::string& a_name, const std::string& a_value)
  : m_name(a_name)
  , m_value(a_value)
{
  // empty
}

std::string
space::name() const
{
  return m_name;
}

std::string
space::value() const
{
  return m_value;
}

} // state namespace
} // compiler namespace
} // hermes namespace
