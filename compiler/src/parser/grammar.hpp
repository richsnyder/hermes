#ifndef HERMES_COMPILER_PARSER_GRAMMAR_HPP
#define HERMES_COMPILER_PARSER_GRAMMAR_HPP

#include "parser/alias.hpp"
#include "parser/common.hpp"
#include "parser/constant.hpp"
#include "parser/datatype.hpp"
#include "parser/enumeration.hpp"
#include "parser/exception.hpp"
#include "parser/interface.hpp"
#include "parser/space.hpp"
#include "parser/structure.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct components : sor<
    alias,
    constant,
    enumeration,
    exception,
    interface,
    space,
    structure
  > {};

struct grammar : star<sor<components, semicolon, skip>> {};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_GRAMMAR_HPP
