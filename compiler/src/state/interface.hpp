#ifndef HERMES_COMPILER_STATE_INTERFACE_HPP
#define HERMES_COMPILER_STATE_INTERFACE_HPP

#include <memory>
#include <set>
#include "state/procedure.hpp"

namespace hermes {
namespace compiler {
namespace state {

class interface
{
public:
  interface() = delete;
  interface(interface&&) = default;
  interface(const interface&) = default;
  interface& operator=(interface&&) = default;
  interface& operator=(const interface&) = delete;
  interface(const std::string& a_name);

  std::string name() const;
  const std::vector<procedure>& procedures() const;
  std::set<std::shared_ptr<exception>> exceptions() const;

  void add(const std::string& a_name,
           std::shared_ptr<datatype> a_result,
           const std::vector<field>& a_parameters,
           const std::vector<std::shared_ptr<exception>>& a_exceptions);
private:
  std::string m_name;
  std::vector<procedure> m_procedures;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<hermes::compiler::state::interface>
{
  using interface = hermes::compiler::state::interface;

  bool operator()(const interface& lhs, const interface& rhs) const
  {
    return lhs.name() < rhs.name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_INTERFACE_HPP
