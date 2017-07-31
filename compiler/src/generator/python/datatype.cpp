#include "generator/python/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

datatype::datatype(const std::string& a_name)
  : m_name(a_name)
  , m_numpy_type("object_")
{
  // empty
}

datatype::datatype(const std::string& a_name, const std::string& a_numpy_type)
  : m_name(a_name)
  , m_numpy_type(a_numpy_type)
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

std::string
datatype::numpy_type() const
{
  return m_numpy_type;
}

void
datatype::pack(std::ostream& a_out,
               const std::string& a_variable,
               bool a_numpy) const
{
  a_out << tab << a_variable << ".write(xdr)" << std::endl;
}

void
datatype::unpack(std::ostream& a_out,
                 const std::string& a_variable,
                 bool a_numpy) const
{
  a_out << tab << a_variable << " = " << m_name << ".read(xdr)" << std::endl;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
