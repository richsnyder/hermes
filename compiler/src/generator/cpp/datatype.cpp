#include "generator/cpp/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

datatype::datatype(const std::string& a_name)
  : m_name(a_name)
{
  // empty
}

datatype::~datatype()
{
  // empty
}

std::string
datatype::name() const
{
  return m_name;
}

void
datatype::rename(const std::string& a_name)
{
  m_name = a_name;
}

std::string
datatype::value_type() const
{
  return name();
}

std::string
datatype::reference() const
{
  return name() + '&';
}

std::string
datatype::const_reference() const
{
  return "const " + name() + '&';
}

std::string
datatype::param_type() const
{
  return "const " + name() + '&';
}

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
