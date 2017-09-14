#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_ENUMERATION_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_ENUMERATION_HPP

#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class enumeration : public datatype
{
public:
  enumeration() = default;
  enumeration(enumeration&&) = delete;
  enumeration(const enumeration &) = delete;
  enumeration& operator=(enumeration&&) = delete;
  enumeration& operator=(const enumeration&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_ENUMERATION_HPP
