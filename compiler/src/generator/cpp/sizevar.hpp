#ifndef HERMES_COMPILER_GENERATOR_CPP_SIZEVAR_HPP
#define HERMES_COMPILER_GENERATOR_CPP_SIZEVAR_HPP

#include "generator/cpp/sizer.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

namespace internal {

class size_manipulator
{
public:
  size_manipulator(const std::string& a_name, std::shared_ptr<sizer> a_value);

  std::string name() const;
  std::shared_ptr<sizer> value() const;
private:
  std::string m_name;
  std::shared_ptr<sizer> m_value;
};

template <class CharT, class Traits>
std::basic_ostream<CharT, Traits>&
operator<<(std::basic_ostream<CharT, Traits>& a_out,
           const size_manipulator& a_manipulator)
{
  std::string name = a_manipulator.name();
  std::string value = static_cast<std::string>(*a_manipulator.value());
  a_out << "std::size_t " << name << " = " << value << ";" << std::endl;
  return a_out;
}

} // internal namespace

internal::size_manipulator
sizevar(const std::string& a_name, std::shared_ptr<sizer> a_sizer);

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_SIZEVAR_HPP
