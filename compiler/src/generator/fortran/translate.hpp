#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_TRANSLATE_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_TRANSLATE_HPP

#include <memory>
#include "state/alias.hpp"
#include "state/container.hpp"
#include "state/datatype.hpp"
#include "state/exception.hpp"
#include "state/structure.hpp"

#include "generator/fortran/alias.hpp"
#include "generator/fortran/basic.hpp"
#include "generator/fortran/container.hpp"
#include "generator/fortran/enumeration.hpp"
#include "generator/fortran/exception.hpp"
#include "generator/fortran/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

std::shared_ptr<datatype>
translate(std::shared_ptr<state::datatype> a_datatype);

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_TRANSLATE_HPP
