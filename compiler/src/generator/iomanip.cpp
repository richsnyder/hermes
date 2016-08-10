#include "generator/iomanip.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace internal {

int
indentation_index()
{
  static int index = std::ios_base::xalloc();
  return index;
}

int
tabmode_index()
{
  static int index = std::ios_base::xalloc();
  return index;
}

int
tabsize_index()
{
  static int index = std::ios_base::xalloc();
  return index;
}

tabsize_manipulator::tabsize_manipulator(size_t a_size)
  : m_size(a_size)
{
  // empty
}

size_t
tabsize_manipulator::size() const
{
  return m_size;
}

} // internal namespace

internal::tabsize_manipulator
tabsize(size_t a_size)
{
  return internal::tabsize_manipulator(a_size);
}

} // generator namespace
} // compiler namespace
} // hermes namespace
