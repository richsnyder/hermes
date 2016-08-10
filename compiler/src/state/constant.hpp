#ifndef HERMES_COMPILER_STATE_CONSTANT_HPP
#define HERMES_COMPILER_STATE_CONSTANT_HPP

#include <cstdint>
#include <memory>
#include <boost/variant.hpp>
#include "state/basic.hpp"

namespace hermes {
namespace compiler {
namespace state {

class constant
{
public:
  typedef std::shared_ptr<datatype> pointer;
  typedef boost::variant<
      bool,
      char,
      std::int8_t,
      std::int16_t,
      std::int32_t,
      std::int64_t,
      std::uint8_t,
      std::uint16_t,
      std::uint32_t,
      std::uint64_t,
      float,
      double,
      std::string
    > value_type;

  constant() = delete;
  constant(constant&&) = default;
  constant(const constant&) = delete;
  constant& operator=(constant&&) = default;
  constant& operator=(const constant&) = delete;
  constant(const std::string& a_name, const value_type& a_value);

  std::string name() const;
  pointer type() const;
  value_type value() const;
protected:
  class visitor : public boost::static_visitor<pointer>
  {
  public:
    result_type operator()(bool) const;
    result_type operator()(char) const;
    result_type operator()(std::int8_t) const;
    result_type operator()(std::int16_t) const;
    result_type operator()(std::int32_t) const;
    result_type operator()(std::int64_t) const;
    result_type operator()(std::uint8_t) const;
    result_type operator()(std::uint16_t) const;
    result_type operator()(std::uint32_t) const;
    result_type operator()(std::uint64_t) const;
    result_type operator()(float) const;
    result_type operator()(double) const;
    result_type operator()(const std::string&) const;
  };
private:
  std::string m_name;
  value_type m_value;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<hermes::compiler::state::constant>
{
  using constant = hermes::compiler::state::constant;

  bool operator()(const constant& lhs, const constant& rhs) const
  {
    return lhs.name() < rhs.name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_CONSTANT_HPP
