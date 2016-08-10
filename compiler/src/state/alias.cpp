#include "state/alias.hpp"

namespace hermes {
namespace compiler {
namespace state {

alias::alias(const std::string& a_name, pointer a_type)
  : datatype(a_name)
  , m_type(std::move(a_type))
{
  // empty
}

bool
alias::is_alias() const
{
  return true;
}

alias::pointer
alias::type() const
{
  return m_type;
}

alias::pointer
alias::root_type() const
{
  pointer p = m_type;
  while (p->is_alias())
  {
    p = std::dynamic_pointer_cast<alias>(p)->type();
  }
  return p;
}

} // state namespace
} // compiler namespace
} // hermes namespace
