#ifndef HERMES_COMPILER_STATE_PROCEDURE_HPP
#define HERMES_COMPILER_STATE_PROCEDURE_HPP

#include <vector>
#include "state/exception.hpp"
#include "state/field.hpp"

namespace hermes {
namespace compiler {
namespace state {

class procedure
{
public:
  typedef std::shared_ptr<datatype> pointer;
  typedef std::shared_ptr<exception> exception_pointer;

  procedure() = default;
  procedure(procedure&&) = default;
  procedure(const procedure&) = default;
  procedure& operator=(procedure&&) = default;
  procedure& operator=(const procedure&) = delete;
  procedure(const std::string& a_name,
            pointer a_result,
            const std::vector<field>& a_parameters,
            const std::vector<exception_pointer>& a_exceptions);

  std::string name() const;
  pointer result() const;
  const std::vector<field>& parameters() const;
  const std::vector<exception_pointer>& exceptions() const;
private:
  std::string m_name;
  pointer m_result;
  std::vector<field> m_parameters;
  std::vector<exception_pointer> m_exceptions;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_PROCEDURE_HPP
