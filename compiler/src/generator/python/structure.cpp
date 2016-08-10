#include "generator/python/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

structure::structure(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : datatype(a_name)
  , m_fields(a_fields)
{
  // empty
}

const std::vector<field>&
structure::fields() const
{
  return m_fields;
}

std::string
structure::default_value() const
{
  return name() + "()";
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
