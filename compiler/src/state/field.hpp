#ifndef HERMES_COMPILER_STATE_FIELD_HPP
#define HERMES_COMPILER_STATE_FIELD_HPP

#include <memory>
#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

class field
{
public:
  typedef std::shared_ptr<datatype> pointer;

  field() = delete;
  field(field&&) = default;
  field(const field&) = default;
  field& operator=(field&&) = default;
  field& operator=(const field&) = delete;
  field(const std::string& a_name, pointer a_type);

  std::string name() const;
  pointer type() const;
private:
  std::string m_name;
  pointer m_type;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_FIELD_HPP
