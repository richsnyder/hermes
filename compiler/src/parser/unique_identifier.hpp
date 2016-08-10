#ifndef HERMES_COMPILER_PARSER_UNIQUE_IDENTIFIER_HPP
#define HERMES_COMPILER_PARSER_UNIQUE_IDENTIFIER_HPP

#include "parser/id.hpp"

namespace hermes {
namespace compiler {
namespace parser {

class unique_identifier : public id
{
public:
  template <
      apply_mode A,
      template <typename ... > class Action,
      template <typename ... > class Control
    >
  static bool match(input& a_input, const state::blueprint& a_blueprint)
  {
    if (!a_input.empty())
    {
      std::string id = identifier(a_input);
      if (!id.empty())
      {
        auto match = a_blueprint.find(id);
        if (!match)
        {
          a_input.bump(id.size());
          return true;
        }
      }
    }
    return false;
  }
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_UNIQUE_IDENTIFIER_HPP
