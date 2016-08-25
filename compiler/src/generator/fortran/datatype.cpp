#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

std::string
datatype::out() const
{
  return in();
}

std::string
datatype::target() const
{
  return out() + ", target";
}

std::string
datatype::member() const
{
  return in();
}

bool
datatype::allocatable() const
{
  return false;
}

std::set<std::string>
datatype::iso_c_symbols() const
{
  return std::set<std::string>();
}

std::set<std::string>
datatype::structures() const
{
  return std::set<std::string>();
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
