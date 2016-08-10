#include "hermes/client.hpp"

namespace hermes {

client::client(void* a_context, const std::string& a_endpoint, int a_type)
{
  m_socket = zmq_socket(a_context, a_type);
  int code = zmq_connect(m_socket, a_endpoint.c_str());
  if (code < 0)
  {
    throw error(zmq_strerror(errno));
  }
}

client::~client()
{
  if (m_socket)
  {
    zmq_close(m_socket);
  }
}

void
client::close()
{
  if (m_socket)
  {
    int code = zmq_close(m_socket);
    if (code < 0)
    {
      throw error(zmq_strerror(errno));
    }
    m_socket = nullptr;
  }
}

} // hermes namespace
