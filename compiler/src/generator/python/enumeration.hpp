#ifndef HERMES_COMPILER_GENERATOR_PYTHON_ENUMERATION_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_ENUMERATION_HPP

#include "generator/python/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

class enumeration : public datatype
{
public:
  enumeration();
  enumeration(enumeration&&) = delete;
  enumeration(const enumeration &) = delete;
  enumeration& operator=(enumeration&&) = delete;
  enumeration& operator=(const enumeration&) = delete;

  std::string default_value() const;

  void pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy) const;
  void unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy) const;
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_ENUMERATION_HPP
