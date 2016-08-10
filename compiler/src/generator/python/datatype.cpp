#include "generator/python/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

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
datatype::pack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << a_variable << ".write(xdr)" << std::endl;
}

void
datatype::unpack(std::ostream& a_out, const std::string& a_variable) const
{
  a_out << tab << a_variable << " = " << m_name << ".read(xdr)" << std::endl;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
