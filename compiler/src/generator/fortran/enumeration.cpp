#include "generator/fortran/enumeration.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

std::string
enumeration::in() const
{
  return "integer(kind = c_int32_t)";
}

std::set<std::string>
enumeration::iso_c_symbols() const
{
  return { "c_int32_t" };
}

std::shared_ptr<sizer>
enumeration::size(const std::string& a_variable) const
{
  return std::make_shared<sizer>(a_variable, 4);
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
