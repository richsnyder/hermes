#ifndef HERMES_HEADER_HPP
#define HERMES_HEADER_HPP

#include <cinttypes>
#include <cstring>
#include <zmq.h>
#include "hermes/error.hpp"

namespace hermes {
namespace internal {

class header
{
public:
  header() = delete;
  header(const header&) = delete;

  std::uint8_t  magic() const;
  std::uint32_t number() const;

  std::size_t size() const;
  const void* data() const;
  bool more() const;

  void send(void* a_socket);
protected:
  header(void* a_socket);
  header(std::uint8_t a_magic, std::uint32_t a_number, bool a_more);
private:
  bool m_more;
  std::uint64_t m_encoding;
};

} // internal namespace
} // hermes namespace

namespace hermes {

class request_header : public internal::header
{
public:
  request_header(std::uint32_t a_number, bool a_more);
  request_header(void* a_socket);
};

class reply_header : public internal::header
{
public:
  reply_header(std::uint32_t a_number, bool a_more);
  reply_header(void* a_socket);
};

} // hermes namespace

#endif // HERMES_HEADER_HPP
