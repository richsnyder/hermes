#ifndef HERMES_COMPILER_PARSER_CONSTANT_HPP
#define HERMES_COMPILER_PARSER_CONSTANT_HPP

#include "pegtl/pegtl.hh"
#include "parser/basic.hpp"
#include "parser/common.hpp"
#include "parser/value.hpp"
#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct constant_bool : if_must<
    bool_keyword,
    skip,
    identifier,
    equal,
    bool_
  > {};
struct constant_char : if_must<
    char_keyword,
    skip,
    identifier,
    equal,
    one<'\''>,
    char_,
    one<'\''>
  > {};
struct constant_int8 : if_must<
    int8_keyword,
    skip,
    identifier,
    equal,
    int_
  > {};
struct constant_int16 : if_must<
    int16_keyword,
    skip,
    identifier,
    equal,
    int_
  > {};
struct constant_int32 : if_must<
    int32_keyword,
    skip,
    identifier,
    equal,
    int_
  > {};
struct constant_int64 : if_must<
    int64_keyword,
    skip,
    identifier,
    equal,
    int_
  > {};
struct constant_uint8 : if_must<
    uint8_keyword,
    skip,
    identifier,
    equal,
    uint_
  > {};
struct constant_uint16 : if_must<
    uint16_keyword,
    skip,
    identifier,
    equal,
    uint_
  > {};
struct constant_uint32 : if_must<
    uint32_keyword,
    skip,
    identifier,
    equal,
    uint_
  > {};
struct constant_uint64 : if_must<
    uint64_keyword,
    skip,
    identifier,
    equal,
    uint_
  > {};
struct constant_real32 : if_must<
    real32_keyword,
    skip,
    identifier,
    equal,
    real_
  > {};
struct constant_real64 : if_must<
    real64_keyword,
    skip,
    identifier,
    equal,
    real_
  > {};
struct constant_string : seq<
    string_keyword,
    skip,
    identifier,
    equal,
    one<'"'>,
    string_,
    one<'"'>
  > {};

struct constant_keyword : pegtl_string_t("constant") {};
struct constant_begin : seq<constant_keyword, skip> {};
struct constant_content : sor<
    constant_bool,
    constant_char,
    constant_int8,
    constant_int16,
    constant_int32,
    constant_int64,
    constant_uint8,
    constant_uint16,
    constant_uint32,
    constant_uint64,
    constant_real32,
    constant_real64,
    constant_string
  >
{
  using bool_t = constant_bool;
  using char_t = constant_char;
  using int8 = constant_int8;
};
struct constant_end : semicolon {};
struct constant : if_must<
    constant_begin,
    constant_content,
    constant_end
  >
{
  using keyword = constant_keyword;
  using begin = constant_begin;
  using content = constant_content;
  using end = constant_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_CONSTANT_HPP
