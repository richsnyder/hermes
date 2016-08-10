#ifndef HERMES_COMPILER_GENERATOR_JOINER_HPP
#define HERMES_COMPILER_GENERATOR_JOINER_HPP

#include <iostream>
#include <string>
#include <vector>

namespace hermes {
namespace compiler {
namespace generator {

template <typename Iterator, typename Function>
class joiner
{
public:
  joiner(Iterator a_begin, Iterator a_end, Function a_function)
    : m_begin(a_begin)
    , m_end(a_end)
    , m_function(a_function)
    , m_left("")
    , m_right("")
    , m_separator(", ")
  {
    // empty
  }

  joiner&
  left(const std::string& a_left)
  {
    m_left = a_left;
    return *this;
  }

  joiner&
  right(const std::string& a_right)
  {
    m_right = a_right;
    return *this;
  }

  joiner&
  separator(const std::string& a_separator)
  {
    m_separator = a_separator;
    return *this;
  }

  std::ostream&
  operator()(std::ostream& a_out) const
  {
    bool first = true;
    a_out << m_left;
    for (auto p = m_begin; p != m_end; ++p)
    {
      if (first)
      {
        first = false;
      }
      else
      {
        a_out << m_separator;
      }
      m_function(a_out, *p);
    }
    a_out << m_right;
    return a_out;
  }
private:
  Iterator m_begin;
  Iterator m_end;
  Function m_function;
  std::string m_left;
  std::string m_right;
  std::string m_separator;
};

template <typename Iterator, typename Function>
std::ostream&
operator<<(std::ostream& a_out, const joiner<Iterator, Function>& a_joiner)
{
  return a_joiner(a_out);
}

template <typename Iterator, typename Function>
joiner<Iterator, Function>
join(Iterator a_begin, Iterator a_end, Function a_function)
{
  return joiner<Iterator, Function>(a_begin, a_end, a_function);
}

} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_JOINER_HPP
