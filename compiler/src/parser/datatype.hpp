#ifndef HERMES_COMPILER_PARSER_DATATYPE_HPP
#define HERMES_COMPILER_PARSER_DATATYPE_HPP

#include "parser/basic.hpp"
#include "parser/container.hpp"
#include "parser/handle.hpp"

namespace hermes {
namespace compiler {
namespace parser {

struct datatype : sor<
    basic,
    container,
    handle
  >
{
  using basic = basic;
  using container = container;
  using handle = handle;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_DATATYPE_HPP
