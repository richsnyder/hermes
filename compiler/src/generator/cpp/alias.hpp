#ifndef HERMES_COMPILER_GENERATOR_CPP_ALIAS_HPP
#define HERMES_COMPILER_GENERATOR_CPP_ALIAS_HPP

#include "generator/cpp/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class alias : public datatype
{
public:
  typedef std::shared_ptr<datatype> pointer;

  alias() = delete;
  alias(alias&&) = delete;
  alias(const alias &) = delete;
  alias& operator=(alias&&) = delete;
  alias& operator=(const alias&) = delete;
  alias(const std::string& a_name, pointer a_type);

  std::string value_type() const;
  std::string reference() const;
  std::string const_reference() const;
  std::string param_type() const;
private:
  pointer m_type;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_ALIAS_HPP
