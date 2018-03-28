#ifndef HERMES_COMPILER_GENERATOR_CPP_DATATYPE_HPP
#define HERMES_COMPILER_GENERATOR_CPP_DATATYPE_HPP

#include <iostream>
#include <memory>
#include <string>
#include "generator/cpp/sizer.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class datatype
{
public:
  datatype() = delete;
  datatype(datatype&&) = delete;
  datatype(const datatype &) = delete;
  datatype& operator=(datatype&&) = delete;
  datatype& operator=(const datatype&) = delete;

  virtual ~datatype();

  virtual std::string name() const;
  void rename(const std::string& a_name);

  virtual std::string value_type() const;
  virtual std::string reference() const;
  virtual std::string const_reference() const;
  virtual std::string param_type() const;

  virtual std::shared_ptr<sizer> size(const std::string& a_variable) const = 0;
protected:
  datatype(const std::string& a_name);
private:
  std::string m_name;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_DATATYPE_HPP
