#ifndef HERMES_COMPILER_PARSER_COMMON_HPP
#define HERMES_COMPILER_PARSER_COMMON_HPP

#include "pegtl/pegtl.hh"
#include "parser/comment.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct skip : sor<space, c_comment, cpp_comment> {};

struct comma : pad<string<','>, skip> {};
struct equal : pad<string<'='>, skip> {};
struct semicolon : seq<star<skip>, one<';'>> {};

struct left_brace : pad<string<'{'>, skip> {};
struct right_brace : pad<string<'}'>, skip> {};
struct left_chevron : seq<one<'<'>, star<skip>> {};
struct right_chevron : seq<star<skip>, one<'>'>> {};
struct left_parenthesis : pad<string<'('>, skip> {};
struct right_parenthesis : pad<string<')'>, skip> {};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_COMMON_HPP
