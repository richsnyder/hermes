#include "hermes/memory.hpp"

namespace hermes {

void free(void* a_data, void* a_hint)
{
  std::free(a_data);
}

} // hermes namespace
