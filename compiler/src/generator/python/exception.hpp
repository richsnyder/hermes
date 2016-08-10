#ifndef HERMES_COMPILER_GENERATOR_PYTHON_EXCEPTION_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_EXCEPTION_HPP

#include "generator/python/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

class exception : public structure
{
public:
  exception() = delete;
  exception(exception&&) = delete;
  exception(const exception&) = delete;
  exception& operator=(exception&&) = delete;
  exception& operator=(const exception&) = delete;
  exception(const std::string& a_name, const std::vector<field>& a_fields);
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_EXCEPTION_HPP
