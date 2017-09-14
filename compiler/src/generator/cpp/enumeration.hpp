#ifndef HERMES_COMPILER_GENERATOR_CPP_ENUMERATION_HPP
#define HERMES_COMPILER_GENERATOR_CPP_ENUMERATION_HPP

#include "generator/iomanip.hpp"
#include "generator/cpp/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class enumeration : public datatype
{
public:
  enumeration() = delete;
  enumeration(enumeration&&) = delete;
  enumeration(const enumeration &) = delete;
  enumeration& operator=(enumeration&&) = delete;
  enumeration& operator=(const enumeration&) = delete;
  enumeration(const std::string& a_name);

  std::string param_type() const;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_ENUMERATION_HPP
