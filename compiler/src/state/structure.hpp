#ifndef HERMES_COMPILER_STATE_STRUCTURE_HPP
#define HERMES_COMPILER_STATE_STRUCTURE_HPP

#include <vector>
#include "state/field.hpp"

namespace hermes {
namespace compiler {
namespace state {

class structure : public datatype
{
public:
  structure() = delete;
  structure(structure&&) = default;
  structure(const structure&) = delete;
  structure& operator=(structure&&) = default;
  structure& operator=(const structure&) = delete;
  structure(const std::string& a_name, const std::vector<field>& a_fields);

  bool is_structure() const;

  const std::vector<field>& fields() const;
private:
  std::vector<field> m_fields;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<std::shared_ptr<hermes::compiler::state::structure>>
{
  using structure = hermes::compiler::state::structure;
  using pointer = std::shared_ptr<structure>;

  bool operator()(const pointer lhs, const pointer rhs) const
  {
    return lhs->name() < rhs->name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_STRUCTURE_HPP
