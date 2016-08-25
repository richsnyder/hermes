#include "generator/fortran/container.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

bool
container::allocatable() const
{
  return true;
}

std::string
container::member() const
{
  return out();
}

map::map(pointer a_key_type, pointer a_value_type)
  : m_key_type(a_key_type)
  , m_value_type(a_value_type)
{
  // empty
}

std::string
map::in() const
{
  return "<>";
}

std::string
map::out() const
{
  return "<>";
}

std::set<std::string>
map::iso_c_symbols() const
{
  std::set<std::string> symbols;
  const auto& k = m_key_type->iso_c_symbols();
  const auto& v = m_value_type->iso_c_symbols();
  auto inserter = std::inserter(symbols, symbols.begin());
  std::merge(k.begin(), k.end(), v.begin(), v.end(), inserter);
  return symbols;
}

std::set<std::string>
map::structures() const
{
  std::set<std::string> symbols;
  const auto& k = m_key_type->structures();
  const auto& v = m_value_type->structures();
  auto inserter = std::inserter(symbols, symbols.begin());
  std::merge(k.begin(), k.end(), v.begin(), v.end(), inserter);
  return symbols;
}

std::shared_ptr<sizer>
map::size(const std::string& a_variable) const
{
  std::shared_ptr<sizer> key_sizer = m_key_type->size(a_variable);
  std::shared_ptr<sizer> value_sizer = m_value_type->size(a_variable);
  auto map_sizer = std::make_shared<sizer>(a_variable, "[size({})]", key_sizer);
  map_sizer->link(std::make_shared<sizer>(a_variable, "[size({})]", value_sizer));
  return map_sizer;
}

set::set(pointer a_key_type)
  : m_key_type(a_key_type)
{
  // empty
}

std::string
set::in() const
{
  return m_key_type->in() + ", dimension(:)";
}

std::string
set::out() const
{
  return m_key_type->out() + ", dimension(:), allocatable";
}

std::set<std::string>
set::iso_c_symbols() const
{
  return m_key_type->iso_c_symbols();
}

std::set<std::string>
set::structures() const
{
  return m_key_type->structures();
}

std::shared_ptr<sizer>
set::size(const std::string& a_variable) const
{
  std::shared_ptr<sizer> key_sizer = m_key_type->size(a_variable);
  return std::make_shared<sizer>(a_variable, "[size({})]", key_sizer);
}

vector::vector(pointer a_value_type)
  : m_value_type(a_value_type)
{
  // empty
}

std::string
vector::in() const
{
  return m_value_type->in() + ", dimension(:)";
}

std::string
vector::out() const
{
  return m_value_type->out() + ", dimension(:), allocatable";
}

std::set<std::string>
vector::iso_c_symbols() const
{
  return m_value_type->iso_c_symbols();
}

std::set<std::string>
vector::structures() const
{
  return m_value_type->structures();
}

std::shared_ptr<sizer>
vector::size(const std::string& a_variable) const
{
  std::shared_ptr<sizer> value_sizer = m_value_type->size(a_variable);
  return std::make_shared<sizer>(a_variable, "[size({})]", value_sizer);
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
