#ifndef HERMES_COMPILER_GENERATOR_PYTHON_TRANSLATE_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_TRANSLATE_HPP

#include <memory>
#include "state/alias.hpp"
#include "state/container.hpp"
#include "state/datatype.hpp"
#include "state/exception.hpp"
#include "state/structure.hpp"

#include "generator/utilities.hpp"
#include "generator/python/alias.hpp"
#include "generator/python/basic.hpp"
#include "generator/python/container.hpp"
#include "generator/python/enumeration.hpp"
#include "generator/python/exception.hpp"
#include "generator/python/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

std::shared_ptr<datatype>
translate(std::shared_ptr<state::datatype> a_datatype);

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_TRANSLATE_HPP
