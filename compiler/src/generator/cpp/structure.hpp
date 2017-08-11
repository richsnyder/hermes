#ifndef HERMES_COMPILER_GENERATOR_CPP_STRUCTURE_HPP
#define HERMES_COMPILER_GENERATOR_CPP_STRUCTURE_HPP

#include <vector>
#include "generator/iomanip.hpp"
#include "generator/cpp/field.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class structure : public datatype
{
public:
  structure() = delete;
  structure(structure&&) = delete;
  structure(const structure&) = delete;
  structure& operator=(structure&&) = delete;
  structure& operator=(const structure&) = delete;
  structure(const std::string& a_name, const std::vector<field>& a_fields);

  const std::vector<field>& fields() const;
private:
  std::vector<field> m_fields;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_STRUCTURE_HPP
