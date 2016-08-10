#include "generator/cpp/exception.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

exception::exception(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : structure(a_name, a_fields)
{
  // empty
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
