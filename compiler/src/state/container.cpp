#include "state/container.hpp"

namespace hermes {
namespace compiler {
namespace state {

container::container(const std::string& a_name)
  : datatype(a_name)
{
  // empty
}

bool
container::is_container() const
{
  return true;
}

map::map(pointer a_key_type, pointer a_value_type)
  : container("map<" + a_key_type->name() + "," + a_value_type->name() + ">")
  , m_key_type(std::move(a_key_type))
  , m_value_type(std::move(a_value_type))
{
  // empty
}

bool
map::is_map() const
{
  return true;
}

map::pointer
map::key_type() const
{
  return m_key_type;
}

map::pointer
map::value_type() const
{
  return m_value_type;
}

set::set(pointer a_key_type)
  : container("set<" + a_key_type->name() + ">")
  , m_key_type(a_key_type)
{
  // empty
}

bool
set::is_set() const
{
  return true;
}

set::pointer
set::key_type() const
{
  return m_key_type;
}

vector::vector(pointer a_value_type)
  : container("vector<" + a_value_type->name() + ">")
  , m_value_type(a_value_type)
{
  // empty
}

bool
vector::is_vector() const
{
  return true;
}

vector::pointer
vector::value_type() const
{
  return m_value_type;
}

} // state namespace
} // compiler namespace
} // hermes namespace
