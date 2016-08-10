#include "parser/id.hpp"

namespace hermes {
namespace compiler {
namespace parser {

bool
id::first(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

bool
id::other(char c)
{
  return first(c) || (c >= '0' && c <= '9');
}

std::string
id::identifier(const input& a_input)
{
  const char* b = a_input.begin();
  if (!first(*b))
  {
    return std::string();
  }

  std::size_t n = 1;
  std::size_t size = a_input.size();
  while (n < size)
  {
    if (!other(*(b + n)))
    {
      break;
    }
    ++n;
  }

  return std::string(b, b + n);
}

} // parser namespace
} // compiler namespace
} // hermes namespace
