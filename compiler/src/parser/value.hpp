#ifndef HERMES_COMPILER_PARSER_VALUES_HPP
#define HERMES_COMPILER_PARSER_VALUES_HPP

#include "pegtl/pegtl.hh"

namespace hermes {
namespace compiler {
namespace parser {

struct bool_ : sor<pegtl_string_t("true"), pegtl_string_t("false")> {};
struct char_ : print {};
struct int_ : seq<opt<one<'+', '-'>>, plus<digit>> {};
struct real_ : seq<
    opt<one<'+', '-'>>,
    sor<
        seq<
            if_then_else<
                one<'.'>,
                plus<digit>,
                seq<plus<digit>, one<'.'>, star<digit>>
              >,
            opt<one<'e', 'E'>, seq<one<'+', '-'>, plus<digit>>>
          >,
        seq<
            one<'0'>,
            one<'x', 'X'>,
            if_then_else<
                one<'.'>,
                plus<xdigit>,
                seq<plus<xdigit>, one<'.'>, star<xdigit>>
              >,
            opt<one<'p', 'P'>, seq<one<'+', '-'>, plus<digit>>>
          >,
        seq<
            istring<'i','n','f'>,
            opt<istring<'i','n','i','t','y'>>
          >,
        seq<
            istring<'n','a','n'>,
            opt<one<'('>, plus<alnum>, one<')'>>
          >
      >
  > {};
struct string_ : star<sor<string<'\\','"'>, not_one<'"'>>> {};
struct uint_ : seq<opt<one<'+'>>, plus<digit>> {};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_VALUES_HPP
