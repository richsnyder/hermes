#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_FIELD_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_FIELD_HPP

#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class field
{
public:
  typedef std::shared_ptr<datatype> pointer;

  field() = delete;
  field(field&&) = delete;
  field(const field&) = default;
  field& operator=(field&&) = delete;
  field& operator=(const field&) = delete;
  field(const std::string& a_name, pointer a_type);

  std::string name() const;
  pointer type() const;
private:
  std::string m_name;
  pointer m_type;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_FIELD_HPP
