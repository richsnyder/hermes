#include "generator/python/field.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

field::field(const std::string& a_name, pointer a_type)
  : m_name(a_name)
  , m_type(a_type)
{
  // empty
}

std::string
field::name() const
{
  return m_name;
}

field::pointer
field::type() const
{
  return m_type;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
