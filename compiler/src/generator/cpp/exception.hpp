#ifndef HERMES_COMPILER_GENERATOR_CPP_EXCEPTION_HPP
#define HERMES_COMPILER_GENERATOR_CPP_EXCEPTION_HPP

#include "generator/cpp/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

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

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_EXCEPTION_HPP
