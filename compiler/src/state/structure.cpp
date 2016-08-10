#include "state/structure.hpp"

namespace hermes {
namespace compiler {
namespace state {

structure::structure(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : datatype(a_name)
  , m_fields(a_fields)
{
  // empty
}

bool
structure::is_structure() const
{
  return true;
}

const std::vector<field>&
structure::fields() const
{
  return m_fields;
}

} // state namespace
} // compiler namespace
} // hermes namespace
