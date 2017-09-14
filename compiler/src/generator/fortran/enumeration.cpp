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

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
