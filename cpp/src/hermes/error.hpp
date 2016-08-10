#ifndef HERMES_ERROR_HPP
#define HERMES_ERROR_HPP

#include <stdexcept>

namespace hermes {

class error : public std::runtime_error
{
public:
  error(const char* a_what);
  error(const std::string& a_what);
};

} // hermes namespace

#endif // HERMES_ERROR_HPP
