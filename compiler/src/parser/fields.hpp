#ifndef HERMES_COMPILER_PARSER_FIELDS_HPP
#define HERMES_COMPILER_PARSER_FIELDS_HPP

#include "parser/common.hpp"
#include "parser/datatype.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct field_separator : comma {};
struct fields : opt<list<seq<datatype, skip, identifier>, field_separator>>
{
  using separator = field_separator;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_FIELDS_HPP
