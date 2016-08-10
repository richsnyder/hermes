#include "generator/python/exception.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

exception::exception(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : structure(a_name, a_fields)
{
  // empty
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
