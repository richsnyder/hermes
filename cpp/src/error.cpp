#include "hermes/error.hpp"

namespace hermes {

error::error(const char* a_what)
  : std::runtime_error(a_what)
{
  // empty
}

error::error(const std::string& a_what)
  : std::runtime_error(a_what)
{
  // empty
}

} // hermes namespace
