#ifndef HERMES_COMPILER_PARSER_STRUCTURE_HPP
#define HERMES_COMPILER_PARSER_STRUCTURE_HPP

#include "parser/common.hpp"
#include "parser/fields.hpp"
#include "parser/unique_identifier.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct structure_keyword : pegtl_string_t("structure") {};
struct structure_begin : seq<
    structure_keyword,
    skip,
    unique_identifier,
    left_brace
  > {};
struct structure_content : fields {};
struct structure_end : right_brace {};
struct structure : if_must<
    structure_begin,
    structure_content,
    structure_end
  >
{
  using keyword = structure_keyword;
  using begin = structure_begin;
  using content = structure_content;
  using end = structure_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_STRUCTURE_HPP
