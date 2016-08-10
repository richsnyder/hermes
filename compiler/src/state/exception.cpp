#include "state/exception.hpp"

namespace hermes {
namespace compiler {
namespace state {

exception::exception(const std::string& a_name,
                     const std::vector<field>& a_fields)
  : structure(a_name, a_fields)
{
  // empty
}

bool
exception::is_exception() const
{
  return true;
}

} // state namespace
} // compiler namespace
} // hermes namespace
