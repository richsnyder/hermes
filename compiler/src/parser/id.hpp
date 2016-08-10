#ifndef HERMES_COMPILER_PARSER_ID_HPP
#define HERMES_COMPILER_PARSER_ID_HPP

#include "pegtl/pegtl.hh"
#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace parser {

class id
{
protected:
  static bool first(char c);
  static bool other(char c);
  static std::string identifier(const input& a_input);
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_ID_HPP
