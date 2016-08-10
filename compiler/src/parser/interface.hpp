#ifndef HERMES_COMPILER_PARSER_INTERFACE_HPP
#define HERMES_COMPILER_PARSER_INTERFACE_HPP

#include "parser/common.hpp"
#include "parser/fields.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct interface_keyword : pegtl_string_t("interface") {};
struct interface_separator : comma {};
struct interface_begin : seq<
    interface_keyword,
    skip,
    identifier,
    left_brace
  > {};
struct interface_content : opt<
    list<
        seq<
            datatype,
            skip,
            identifier,
            left_parenthesis,
            fields,
            right_parenthesis,
            opt<
                pad<pegtl_string_t("throws"), skip>,
                pad<one<'('>, skip>,
                list<handle, comma>,
                pad<one<')'>, skip>
              >
          >,
        interface_separator
      >
  > {};
struct interface_end : right_brace {};
struct interface : if_must<
    interface_begin,
    interface_content,
    interface_end
  >
{
  using keyword = interface_keyword;
  using separator = interface_separator;
  using begin = interface_begin;
  using content = interface_content;
  using end = interface_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_INTERFACE_HPP
