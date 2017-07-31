#ifndef HERMES_COMPILER_GENERATOR_GENERATE_HPP
#define HERMES_COMPILER_GENERATOR_GENERATE_HPP

#include "json/json.hpp"
#include "state/blueprint.hpp"
#include "generator/cpp/generator.hpp"
#include "generator/fortran/generator.hpp"
#include "generator/python/generator.hpp"

namespace hermes {
namespace compiler {
namespace generator {

using state::blueprint;

void generate(const std::string& a_language,
              const nlohmann::json& a_options,
              const std::string& a_project,
              const std::string& a_directory,
              const blueprint& a_blueprint);

} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_GENERATE_HPP
