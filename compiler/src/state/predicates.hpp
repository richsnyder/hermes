#ifndef HERMES_COMPILER_STATE_PREDICATES_HPP
#define HERMES_COMPILER_STATE_PREDICATES_HPP

#include <memory>
#include <string>

namespace hermes {
namespace compiler {
namespace state {

template <typename T>
class has_name
{
public:
  typedef std::shared_ptr<T> pointer;

  has_name(const std::string& a_name)
    : m_name(a_name)
  {
    // empty
  }

  bool operator()(const pointer& a_pointer) const
  {
    return a_pointer->name() == m_name;
  }
private:
  std::string m_name;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_PREDICATES_HPP
