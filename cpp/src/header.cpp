#include "hermes/header.hpp"

namespace hermes {
namespace internal {

header::header(void* a_socket)
{
  zmq_msg_t message;
  zmq_msg_init(&message);
  int code = zmq_msg_recv(&message, a_socket, 0);
  if (code < 0)
  {
    throw error(zmq_strerror(errno));
  }
  if (zmq_msg_size(&message) != 8)
  {
    throw error("Expected 8 bytes but received an unexpected amount of data");
  }
  std::memcpy(&m_encoding, zmq_msg_data(&message), 8);
  m_more = zmq_msg_more(&message) == 1;
  code = zmq_msg_close(&message);
  if (code < 0)
  {
    throw error(zmq_strerror(errno));
  }
}

header::header(std::uint8_t a_magic, std::uint32_t a_number, bool a_more)
  : m_more(a_more)
  , m_encoding(
        static_cast<std::uint64_t>(a_magic)
      | (static_cast<std::uint64_t>(a_number) << 32)
    )
{
  // empty
}

std::uint8_t
header::magic() const
{
  return static_cast<std::uint8_t>(m_encoding & 0xFF);
}

std::uint32_t
header::number() const
{
  return static_cast<std::uint32_t>(m_encoding >> 32);
}

std::size_t
header::size() const
{
  return 8;
}

const void*
header::data() const
{
  return reinterpret_cast<const void*>(&m_encoding);
}

bool
header::more() const
{
  return m_more;
}

void
header::send(void* a_socket)
{
  zmq_msg_t message;
  int code = zmq_msg_init_size(&message, 8);
  if (code < 0)
  {
    throw error(zmq_strerror(errno));
  }
  int flags = m_more ? ZMQ_SNDMORE : 0;
  std::memcpy(zmq_msg_data(&message), &m_encoding, 8);
  if (zmq_msg_send(&message, a_socket, flags) != 8)
  {
    throw error("Failed to send an 8 byte header");
  }
}

} // internal namespace
} // hermes namespace

namespace hermes {

request_header::request_header(std::uint32_t a_number, bool a_more)
  : header(0x01, a_number, a_more)
{
  // empty
}

request_header::request_header(void* a_socket)
: header(a_socket)
{
  if (magic() != 0x01)
  {
    throw error("Expected a request but received other data");
  }
}

reply_header::reply_header(std::uint32_t a_number, bool a_more)
  : header(0x02, a_number, a_more)
{
  // empty
}

reply_header::reply_header(void* a_socket)
  : header(a_socket)
{
  if (magic() != 0x02)
  {
    throw error("Expected a reply but received other data");
  }
}

} // hermes namespace
