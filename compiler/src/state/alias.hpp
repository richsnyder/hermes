#ifndef HERMES_COMPILER_STATE_ALIAS_HPP
#define HERMES_COMPILER_STATE_ALIAS_HPP

#include <memory>
#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

class alias : public datatype
{
public:
  typedef std::shared_ptr<datatype> pointer;

  alias() = delete;
  alias(const alias&) = delete;
  alias& operator=(const alias&) = delete;
  alias(const std::string& a_name, pointer a_type);

  bool is_alias() const;

  pointer type() const;
  pointer root_type() const;
private:
  pointer m_type;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<std::shared_ptr<hermes::compiler::state::alias>>
{
  using alias = hermes::compiler::state::alias;
  using pointer = std::shared_ptr<alias>;

  bool operator()(const pointer lhs, const pointer rhs) const
  {
    return lhs->name() < rhs->name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_ALIAS_HPP
