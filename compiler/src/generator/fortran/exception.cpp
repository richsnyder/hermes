#include "generator/fortran/exception.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

exception::exception(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : structure(a_name, a_fields)
{
  // empty
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
