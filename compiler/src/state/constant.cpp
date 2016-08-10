#include "state/constant.hpp"

namespace hermes {
namespace compiler {
namespace state {

constant::constant(const std::string& a_name, const value_type& a_value)
  : m_name(a_name)
  , m_value(a_value)
{
  // empty
}

std::string
constant::name() const
{
  return m_name;
}

constant::pointer
constant::type() const
{
  return boost::apply_visitor(visitor(), m_value);
}

constant::value_type
constant::value() const
{
  return m_value;
}

constant::visitor::result_type
constant::visitor::operator()(bool) const
{
  return std::make_shared<bool_t>();
}

constant::visitor::result_type
constant::visitor::operator()(char) const
{
  return std::make_shared<char_t>();
}

constant::visitor::result_type
constant::visitor::operator()(std::int8_t) const
{
  return std::make_shared<int8>();
}

constant::visitor::result_type
constant::visitor::operator()(std::int16_t) const
{
  return std::make_shared<int16>();
}

constant::visitor::result_type
constant::visitor::operator()(std::int32_t) const
{
  return std::make_shared<int32>();
}

constant::visitor::result_type
constant::visitor::operator()(std::int64_t) const
{
  return std::make_shared<int64>();
}

constant::visitor::result_type
constant::visitor::operator()(std::uint8_t) const
{
  return std::make_shared<uint8>();
}

constant::visitor::result_type
constant::visitor::operator()(std::uint16_t) const
{
  return std::make_shared<uint16>();
}

constant::visitor::result_type
constant::visitor::operator()(std::uint32_t) const
{
  return std::make_shared<uint32>();
}

constant::visitor::result_type
constant::visitor::operator()(std::uint64_t) const
{
  return std::make_shared<uint64>();
}

constant::visitor::result_type
constant::visitor::operator()(float) const
{
  return std::make_shared<real32>();
}

constant::visitor::result_type
constant::visitor::operator()(double) const
{
  return std::make_shared<real64>();
}

constant::visitor::result_type
constant::visitor::operator()(const std::string&) const
{
  return std::make_shared<string>();
}

} // state namespace
} // compiler namespace
} // hermes namespace
