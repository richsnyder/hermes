#ifndef HERMES_IS_BITS_HPP
#define HERMES_IS_BITS_HPP

#include <vector>

namespace hermes {
namespace internal {

template <typename T>
struct is_bits
{
  static const bool value = false;
};

#if defined(__llvm__) || defined(__INTEL_COMPILER)
template <typename T>
struct is_bits<std::__bit_reference<T>>
{
  static const bool value = true;
};

template <typename T>
struct is_bits<std::__bit_const_reference<T>>
{
  static const bool value = true;
};
#endif

} // internal namespace
} // hermes namespace

#endif // HERMES_IS_BITS_HPP
