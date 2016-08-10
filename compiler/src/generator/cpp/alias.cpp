#include "generator/cpp/alias.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

alias::alias(const std::string& a_name, pointer a_type)
  : datatype(a_name)
  , m_type(a_type)
{
  m_type->rename(a_name);
}

std::string
alias::value_type() const
{
  return m_type->value_type();
}

std::string
alias::reference() const
{
  return m_type->reference();
}

std::string
alias::const_reference() const
{
  return m_type->const_reference();
}

std::string
alias::param_type() const
{
  return m_type->param_type();
}

std::shared_ptr<sizer>
alias::size(const std::string& a_variable) const
{
  return m_type->size(a_variable);
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
