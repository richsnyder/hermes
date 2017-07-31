#include "generator/python/enumeration.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

enumeration::enumeration()
  : datatype("int")
{
  // empty
}

std::string
enumeration::default_value() const
{
  return "0";
}

void
enumeration::pack(std::ostream& a_out,
                  const std::string& a_variable,
                  bool a_numpy) const
{
  a_out << tab << "xdr.pack_int(" << a_variable << ")" << std::endl;
}

void
enumeration::unpack(std::ostream& a_out,
                    const std::string& a_variable,
                    bool a_numpy) const
{
  a_out << tab << a_variable << " = xdr.unpack_int()" << std::endl;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
