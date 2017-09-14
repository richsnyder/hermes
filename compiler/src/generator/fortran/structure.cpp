#include "generator/fortran/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

structure::structure(const std::string& a_name, const std::vector<field>& a_fields)
  : m_name(a_name)
  , m_fields(a_fields)
{
  // empty
}

std::string
structure::in() const
{
  return "type(" + m_name + ")";
}

std::set<std::string>
structure::structures() const
{
  return { m_name };
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
