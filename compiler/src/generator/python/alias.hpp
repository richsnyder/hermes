#ifndef HERMES_COMPILER_GENERATOR_PYTHON_ALIAS_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_ALIAS_HPP

#include "generator/python/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

class alias : public datatype
{
public:
  typedef std::shared_ptr<datatype> pointer;

  alias() = delete;
  alias(alias&&) = delete;
  alias(const alias &) = delete;
  alias& operator=(alias&&) = delete;
  alias& operator=(const alias&) = delete;
  alias(pointer a_type);

  std::string name() const;
  std::string default_value() const;
  void pack(std::ostream& a_out, const std::string& a_variable) const;
  void unpack(std::ostream& a_out, const std::string& a_variable) const;
private:
  pointer m_type;
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_ALIAS_HPP
