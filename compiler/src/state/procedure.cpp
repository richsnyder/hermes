#include "state/procedure.hpp"

namespace hermes {
namespace compiler {
namespace state {

procedure::procedure(const std::string& a_name,
                     pointer a_result,
                     const std::vector<field>& a_parameters,
                     const std::vector<exception_pointer>& a_exceptions)
  : m_name(a_name)
  , m_result(std::move(a_result))
  , m_parameters(a_parameters)
  , m_exceptions(a_exceptions)
{
  // empty
}

std::string
procedure::name() const
{
  return m_name;
}

procedure::pointer
procedure::result() const
{
  return m_result;
}

const std::vector<field>&
procedure::parameters() const
{
  return m_parameters;
}

const std::vector<procedure::exception_pointer>&
procedure::exceptions() const
{
  return m_exceptions;
}

} // state namespace
} // compiler namespace
} // hermes namespace
