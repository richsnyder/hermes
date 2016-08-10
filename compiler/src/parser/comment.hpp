#ifndef HERMES_COMPILER_PARSER_COMMENT_HPP
#define HERMES_COMPILER_PARSER_COMMENT_HPP

#include "pegtl/pegtl.hh"

namespace hermes {
namespace compiler {
namespace parser {

struct c_comment_begin : string<'/', '*'> {};
struct c_comment_end : string<'*', '/'> {};
struct c_comment_content : until<c_comment_end, print> {};
struct c_comment : seq<c_comment_begin, c_comment_content>
{
    using begin = c_comment_begin;
    using content = c_comment_content;
    using end = c_comment_end;
};

struct cpp_comment_begin : string<'/', '/'> {};
struct cpp_comment_end : eol {};
struct cpp_comment_content : until<cpp_comment_end, print> {};
struct cpp_comment : seq<cpp_comment_begin, cpp_comment_content>
{
  using begin = cpp_comment_begin;
  using content = cpp_comment_content;
  using end = cpp_comment_end;
};

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_COMMENT_HPP
