#ifndef HERMES_COMPILER_PARSER_CONTAINER_HPP
#define HERMES_COMPILER_PARSER_CONTAINER_HPP

#include "pegtl/pegtl.hh"
#include "parser/common.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct datatype;

struct map_keyword : pegtl_string_t("map") {};
struct map_begin : if_must<map_keyword, left_chevron> {};
struct map_content : seq<datatype, comma, datatype> {};
struct map_end : right_chevron {};
struct map : if_must<
    map_begin,
    map_content,
    map_end
  >
{
  using keyword = map_keyword;
  using begin = map_begin;
  using content = map_content;
  using end = map_end;
};

struct set_keyword : pegtl_string_t("set") {};
struct set_begin : if_must<set_keyword, left_chevron, datatype> {};
struct set_end : right_chevron {};
struct set : if_must<
    set_begin,
    set_end
  >
{
  using keyword = set_keyword;
  using begin = set_begin;
  using end = set_end;
};

struct vector_keyword : pegtl_string_t("vector") {};
struct vector_begin : if_must<vector_keyword, left_chevron, datatype> {};
struct vector_end : right_chevron {};
struct vector : if_must<
    vector_begin,
    vector_end
  >
{
  using keyword = vector_keyword;
  using begin = vector_begin;
  using end = vector_end;
};

struct container : sor<map, set, vector> {};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_CONTAINER_HPP
