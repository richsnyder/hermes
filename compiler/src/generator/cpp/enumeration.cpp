#include "generator/cpp/enumeration.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

enumeration::enumeration(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

std::string
enumeration::param_type() const
{
  return name();
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
