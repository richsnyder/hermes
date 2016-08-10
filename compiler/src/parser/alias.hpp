#ifndef HERMES_COMPILER_PARSER_ALIAS_HPP
#define HERMES_COMPILER_PARSER_ALIAS_HPP

#include "parser/common.hpp"
#include "parser/datatype.hpp"
#include "parser/unique_identifier.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct alias_keyword : pegtl_string_t("alias") {};
struct alias_begin : seq<alias_keyword, plus<skip>> {};
struct alias_content : seq<unique_identifier, equal, datatype> {};
struct alias_end : semicolon {};
struct alias : if_must<
    alias_begin,
    alias_content,
    alias_end
  >
{
  using keyword = alias_keyword;
  using begin = alias_begin;
  using content = alias_content;
  using end = alias_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_ALIAS_HPP
