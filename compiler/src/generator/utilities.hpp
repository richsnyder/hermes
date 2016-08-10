#ifndef HERMES_COMPILER_GENERATOR_UTILITIES_HPP
#define HERMES_COMPILER_GENERATOR_UTILITIES_HPP

#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "generator/joiner.hpp"

namespace hermes {
namespace compiler {
namespace generator {

std::vector<std::string> split(const std::string& a_name);
std::string stem(const std::string& a_path);
std::string to_camel(const std::string& a_label);
std::string to_hex(unsigned long a_value);

} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_UTILITIES_HPP
