#ifndef HERMES_COMPILER_PARSER_IMPORT_HPP
#define HERMES_COMPILER_PARSER_IMPORT_HPP

#include "parser/common.hpp"
#include "parser/datatype.hpp"
#include "parser/value.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct import_keyword : pegtl_string_t("import") {};
struct import_begin : seq<import_keyword, plus<skip>> {};
struct import_content : seq<one<'"'>, string_, one<'"'>> {};
struct import_end : semicolon {};
struct import : if_must<
    import_begin,
    import_content,
    import_end
  >
{
  using keyword = import_keyword;
  using begin = import_begin;
  using content = import_content;
  using end = import_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_IMPORT_HPP
