#ifndef HERMES_COMPILER_GENERATOR_PYTHON_STRUCTURE_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_STRUCTURE_HPP

#include <vector>
#include "generator/python/datatype.hpp"
#include "generator/python/field.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

class structure : public datatype
{
public:
  structure() = delete;
  structure(structure&&) = delete;
  structure(const structure &) = delete;
  structure& operator=(structure&&) = delete;
  structure& operator=(const structure&) = delete;
  structure(const std::string& a_name, const std::vector<field>& a_fields);

  const std::vector<field>& fields() const;

  std::string default_value() const;
private:
  std::vector<field> m_fields;
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_STRUCTURE_HPP
