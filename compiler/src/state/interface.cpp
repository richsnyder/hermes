#include "state/interface.hpp"

namespace hermes {
namespace compiler {
namespace state {

interface::interface(const std::string& a_name)
  : m_name(a_name)
{
  // empty
}

std::string
interface::name() const
{
  return m_name;
}

const std::vector<procedure>&
interface::procedures() const
{
  return m_procedures;
}

std::set<std::shared_ptr<exception>>
interface::exceptions() const
{
  std::set<std::shared_ptr<exception>> exceptions;
  for (const auto& p : m_procedures)
  {
    for (auto e : p.exceptions())
    {
      exceptions.emplace(e);
    }
  }
  return exceptions;
}

void
interface::add(const std::string& a_name,
               std::shared_ptr<datatype> a_result,
               const std::vector<field>& a_parameters,
               const std::vector<std::shared_ptr<exception>>& a_exceptions)
{
  m_procedures.emplace_back(a_name, a_result, a_parameters, a_exceptions);
}

} // state namespace
} // compiler namespace
} // hermes namespace
