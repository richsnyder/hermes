#include "hermes/server.hpp"

namespace hermes {

server::server(void* a_context, const std::string& a_endpoint, int a_type)
{
  m_socket = zmq_socket(a_context, a_type);
  int code = zmq_bind(m_socket, a_endpoint.c_str());
  if (code < 0)
  {
    throw error(zmq_strerror(errno));
  }
}

server::~server()
{
  if (m_socket)
  {
    zmq_close(m_socket);
  }
}

void
server::close()
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

void
server::serve()
{
  while (true)
  {
    serve_once();
  }
}

void
server::serve(int a_count)
{
  for (auto n = 0; n < a_count; ++n)
  {
    serve_once();
  }
}

} // hermes namespace
