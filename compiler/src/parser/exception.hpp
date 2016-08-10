#ifndef HERMES_COMPILER_PARSER_EXCEPTION_HPP
#define HERMES_COMPILER_PARSER_EXCEPTION_HPP

#include "parser/common.hpp"
#include "parser/fields.hpp"
#include "parser/unique_identifier.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct exception_keyword : pegtl_string_t("exception") {};
struct exception_begin : seq<
    exception_keyword,
    skip,
    unique_identifier,
    left_brace
  > {};
struct exception_content : fields {};
struct exception_end : right_brace {};
struct exception : if_must<
    exception_begin,
    exception_content,
    exception_end
  >
{
  using keyword = exception_keyword;
  using begin = exception_begin;
  using content = exception_content;
  using end = exception_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_EXCEPTION_HPP
