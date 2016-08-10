#include "generator/python/alias.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

alias::alias(pointer a_type)
  : datatype("")
  , m_type(a_type)
{
  // empty
}

std::string
alias::name() const
{
  return m_type->name();
}

std::string
alias::default_value() const
{
  return m_type->default_value();
}

void
alias::pack(std::ostream& a_out, const std::string& a_variable) const
{
  m_type->pack(a_out, a_variable);
}

void
alias::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  m_type->pack(a_out, a_variable);
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
