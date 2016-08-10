#ifndef HERMES_COMPILER_PARSER_BASIC_HPP
#define HERMES_COMPILER_PARSER_BASIC_HPP

#include "pegtl/pegtl.hh"

namespace hermes {
namespace compiler {
namespace parser {

struct void_keyword : pegtl_string_t("void") {};
struct bool_keyword : pegtl_string_t("bool") {};
struct char_keyword : pegtl_string_t("char") {};
struct int8_keyword : pegtl_string_t("int8") {};
struct int16_keyword : pegtl_string_t("int16") {};
struct int32_keyword : pegtl_string_t("int32") {};
struct int64_keyword : pegtl_string_t("int64") {};
struct uint8_keyword : pegtl_string_t("uint8") {};
struct uint16_keyword : pegtl_string_t("uint16") {};
struct uint32_keyword : pegtl_string_t("uint32") {};
struct uint64_keyword : pegtl_string_t("uint64") {};
struct real32_keyword : pegtl_string_t("real32") {};
struct real64_keyword : pegtl_string_t("real64") {};
struct string_keyword : pegtl_string_t("string") {};

struct basic : sor<
    void_keyword,
    bool_keyword,
    char_keyword,
    int8_keyword,
    int16_keyword,
    int32_keyword,
    int64_keyword,
    uint8_keyword,
    uint16_keyword,
    uint32_keyword,
    uint64_keyword,
    real32_keyword,
    real64_keyword,
    string_keyword
  >
{
  using void_t = void_keyword;
  using bool_t = bool_keyword;
  using char_t = char_keyword;
  using int8 = int8_keyword;
  using int16 = int16_keyword;
  using int32 = int32_keyword;
  using int64 = int64_keyword;
  using uint8 = uint8_keyword;
  using uint16 = uint16_keyword;
  using uint32 = uint32_keyword;
  using uint64 = uint64_keyword;
  using real32 = real32_keyword;
  using real64 = real64_keyword;
  using string = string_keyword;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_BASIC_HPP
