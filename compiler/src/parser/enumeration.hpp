#ifndef HERMES_COMPILER_PARSER_ENUMERATION_HPP
#define HERMES_COMPILER_PARSER_ENUMERATION_HPP

#include "pegtl/pegtl.hh"
#include "parser/common.hpp"
#include "parser/unique_identifier.hpp"
#include "parser/value.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct enumeration_keyword : pegtl_string_t("enumeration") {};
struct enumeration_separator : comma {};
struct enumeration_begin : seq<
    enumeration_keyword,
    skip,
    unique_identifier,
    left_brace
  > {};
struct enumeration_content : opt<
    list<seq<identifier, opt<equal, int_>>, enumeration_separator>
  > {};
struct enumeration_end : right_brace {};
struct enumeration : if_must<
    enumeration_begin,
    enumeration_content,
    enumeration_end
  >
{
  using keyword = enumeration_keyword;
  using separator = enumeration_separator;
  using begin = enumeration_begin;
  using content = enumeration_content;
  using end = enumeration_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_ENUMERATION_HPP
