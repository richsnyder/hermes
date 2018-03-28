#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_DATATYPE_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_DATATYPE_HPP

#include <iostream>
#include <memory>
#include <set>
#include <string>

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class datatype
{
public:
  datatype() = default;
  datatype(datatype&&) = delete;
  datatype(const datatype &) = delete;
  datatype& operator=(datatype&&) = delete;
  datatype& operator=(const datatype&) = delete;

  virtual std::string in() const = 0;
  virtual std::string out() const;
  virtual std::string target() const;
  virtual std::string member() const;
  virtual bool allocatable() const;
  virtual std::set<std::string> iso_c_symbols() const;
  virtual std::set<std::string> structures() const;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_DATATYPE_HPP
