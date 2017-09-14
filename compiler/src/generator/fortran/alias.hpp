#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_ALIAS_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_ALIAS_HPP

#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class alias : public datatype
{
public:
  typedef std::shared_ptr<datatype> pointer;

  alias() = delete;
  alias(alias&&) = delete;
  alias(const alias &) = delete;
  alias& operator=(alias&&) = delete;
  alias& operator=(const alias&) = delete;
  alias(pointer a_type);

  std::string in() const;
  std::string out() const;
  std::string target() const;
  bool allocatable() const;
  std::set<std::string> iso_c_symbols() const;
  std::set<std::string> structures() const;
private:
  pointer m_type;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_ALIAS_HPP
