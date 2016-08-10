#ifndef HERMES_COMPILER_GENERATOR_CPP_TRANSLATE_HPP
#define HERMES_COMPILER_GENERATOR_CPP_TRANSLATE_HPP

#include <memory>
#include "state/alias.hpp"
#include "state/container.hpp"
#include "state/datatype.hpp"
#include "state/exception.hpp"
#include "state/structure.hpp"
#include "generator/cpp/alias.hpp"
#include "generator/cpp/basic.hpp"
#include "generator/cpp/container.hpp"
#include "generator/cpp/enumeration.hpp"
#include "generator/cpp/exception.hpp"
#include "generator/cpp/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

std::shared_ptr<datatype>
translate(std::shared_ptr<state::datatype> a_datatype);

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_TRANSLATE_HPP
