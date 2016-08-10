#ifndef HERMES_COMPILER_STATE_SPACE_HPP
#define HERMES_COMPILER_STATE_SPACE_HPP

#include <string>

namespace hermes {
namespace compiler {
namespace state {

class space
{
public:
  space() = delete;
  space(const space&) = default;
  space(const std::string& a_name, const std::string& a_value);

  std::string name() const;
  std::string value() const;
private:
  std::string m_name;
  std::string m_value;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<hermes::compiler::state::space>
{
  using space = hermes::compiler::state::space;

  bool operator()(const space& lhs, const space& rhs) const
  {
    return lhs.name() < rhs.name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_SPACE_HPP
