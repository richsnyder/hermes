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

std::shared_ptr<sizer>
enumeration::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
