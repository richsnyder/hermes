#ifndef HERMES_CLIENT_HPP
#define HERMES_CLIENT_HPP

#include <string>
#include <zmq.h>
#include "hermes/error.hpp"

namespace hermes {

class client
{
public:
  client(void* a_context, const std::string& a_endpoint, int a_type);
  virtual ~client();

  void close();
protected:
  void* m_socket;
};

} // hermes namespace

#endif // HERMES_CLIENT_HPP
