#ifndef HERMES_COMPILER_PARSER_CONTROL_HPP
#define HERMES_COMPILER_PARSER_CONTROL_HPP

#include "pegtl/pegtl.hh"
#include "parser/datatype.hpp"

namespace hermes {
namespace compiler {
namespace parser {

template <typename Rule>
struct control : public pegtl::normal<Rule>
{
  static const std::string error_message;

  template <typename Input, typename ... States>
  static void raise(const Input& a_input, States&& ...)
  {
    throw pegtl::parse_error(error_message, a_input);
  }
};

template <typename Rule>
const std::string control<Rule>::error_message =
    "parse error matching <" + internal::demangle<Rule>() + ">";

template <>
const std::string control<datatype>::error_message = "undefined datatype";

} // parser namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_PARSER_CONTROL_HPP
