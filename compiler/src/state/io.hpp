#ifndef HERMES_COMPILER_STATE_IO_HPP
#define HERMES_COMPILER_STATE_IO_HPP

#include <iostream>
#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace state {

std::ostream& operator<<(std::ostream& a_out, const alias& a_alias);
std::ostream& operator<<(std::ostream& a_out, const blueprint& a_blueprint);
std::ostream& operator<<(std::ostream& a_out, const constant& a_constant);
std::ostream& operator<<(std::ostream& a_out, const enumeration& a_enumeration);
std::ostream& operator<<(std::ostream& a_out, const field& a_field);
std::ostream& operator<<(std::ostream& a_out, const interface& a_interface);
std::ostream& operator<<(std::ostream& a_out, const procedure& a_procedure);
std::ostream& operator<<(std::ostream& a_out, const space& a_space);
std::ostream& operator<<(std::ostream& a_out, const structure& a_structure);

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_IO_HPP
