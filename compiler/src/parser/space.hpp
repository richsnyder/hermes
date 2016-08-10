#ifndef HERMES_COMPILER_PARSER_SPACE_HPP
#define HERMES_COMPILER_PARSER_SPACE_HPP

#include "parser/common.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct space_keyword : pegtl_string_t("namespace") {};
struct space_name : plus<sor<ranges<'a','z','A','Z','0','9'>, one<'.','_'>>> {};
struct space_begin : seq<space_keyword, plus<skip>> {};
struct space_content : seq<identifier, equal, space_name> {};
struct space_end : semicolon {};
struct space : if_must<
    space_begin,
    space_content,
    space_end
  >
{
  using keyword = space_keyword;
  using name = space_name;
  using begin = space_begin;
  using content = space_content;
  using end = space_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_SPACE_HPP
