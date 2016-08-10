#ifndef HERMES_COMPILER_STATE_EXCEPTION_HPP
#define HERMES_COMPILER_STATE_EXCEPTION_HPP

#include "state/structure.hpp"

namespace hermes {
namespace compiler {
namespace state {

class exception : public structure
{
public:
  exception() = delete;
  exception(exception&&) = default;
  exception(const exception&) = delete;
  exception& operator=(exception&&) = default;
  exception& operator=(const exception&) = delete;
  exception(const std::string& a_name, const std::vector<field>& a_fields);

  bool is_exception() const;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<std::shared_ptr<hermes::compiler::state::exception>>
{
  using exception = hermes::compiler::state::exception;
  using pointer = std::shared_ptr<exception>;

  bool operator()(const pointer lhs, const pointer rhs) const
  {
    return lhs->name() < rhs->name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_EXCEPTION_HPP
