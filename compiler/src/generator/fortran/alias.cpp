#include "generator/fortran/alias.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

alias::alias(pointer a_type)
  : datatype()
  , m_type(a_type)
{
  // empty
}

std::string
alias::in() const
{
  return m_type->in();
}

std::string
alias::out() const
{
  return m_type->out();
}

std::string
alias::target() const
{
  return m_type->target();
}

bool
alias::allocatable() const
{
  return m_type->allocatable();
}

std::set<std::string>
alias::iso_c_symbols() const
{
  return m_type->iso_c_symbols();
}

std::set<std::string>
alias::structures() const
{
  return m_type->structures();
}

std::shared_ptr<sizer>
alias::size(const std::string& a_variable) const
{
  return m_type->size(a_variable);
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
