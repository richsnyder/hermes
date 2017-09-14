#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_STRUCTURE_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_STRUCTURE_HPP

#include <vector>
#include "generator/fortran/datatype.hpp"
#include "generator/fortran/field.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class structure : public datatype
{
public:
  structure() = default;
  structure(structure&&) = delete;
  structure(const structure &) = delete;
  structure& operator=(structure&&) = delete;
  structure& operator=(const structure&) = delete;
  structure(const std::string& a_name, const std::vector<field>& a_fields);

  std::string in() const;
  std::set<std::string> structures() const;
private:
  std::string m_name;
  std::vector<field> m_fields;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_STRUCTURE_HPP
