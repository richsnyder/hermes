#include "generator/fortran/sizevar.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

namespace internal {

size_manipulator::size_manipulator(const std::string& a_name, std::shared_ptr<sizer> a_value)
  : m_name(a_name)
  , m_value(std::move(a_value))
{
  // empty
}

std::string
size_manipulator::name() const
{
  return m_name;
}

std::shared_ptr<sizer>
size_manipulator::value() const
{
  return m_value;
}

} // internal namespace

internal::size_manipulator
sizevar(const std::string& a_name, std::shared_ptr<sizer> a_sizer)
{
  return internal::size_manipulator(a_name, a_sizer);
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
