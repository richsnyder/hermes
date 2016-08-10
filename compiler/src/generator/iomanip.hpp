#ifndef HERMES_COMPILER_GENERATOR_IOMANIP_HPP
#define HERMES_COMPILER_GENERATOR_IOMANIP_HPP

#include <iostream>

namespace hermes {
namespace compiler {
namespace generator {

namespace internal {

int indentation_index();
int tabmode_index();
int tabsize_index();

class tabsize_manipulator
{
public:
  tabsize_manipulator(size_t a_size);

  size_t size() const;
private:
  size_t m_size;
};

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& a_out,
           const tabsize_manipulator& a_manipulator)
{
  a_out.iword(internal::tabsize_index()) = a_manipulator.size();
  return a_out;
}

} // internal namespace

internal::tabsize_manipulator tabsize(size_t a_size);

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
indent(std::basic_ostream<CharT, Traits>& a_out)
{
  a_out.iword(internal::indentation_index())++;
  return a_out;
}

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
unindent(std::basic_ostream<CharT, Traits>& a_out)
{
  a_out.iword(internal::indentation_index())--;
  return a_out;
}

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
tab(std::basic_ostream<CharT, Traits>& a_out)
{
  long tabsize = a_out.iword(internal::tabsize_index());
  long indentation = a_out.iword(internal::indentation_index());
  char c = (a_out.iword(internal::tabmode_index()) == 1) ? '\t' : ' ';
  for (long i = 0; i < tabsize * indentation; ++i)
  {
    a_out.put(c);
  }
  return a_out;
}

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
use_spaces(std::basic_ostream<CharT, Traits>& a_out)
{
  a_out.iword(internal::tabmode_index()) = 0;
  return a_out;
}

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
use_tabs(std::basic_ostream<CharT, Traits>& a_out)
{
  a_out.iword(internal::tabmode_index()) = 1;
  return a_out;
}

} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_IOMANIP_HPP
