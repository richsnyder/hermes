#include "hermes/archive.hpp"

namespace hermes {

iarchive::iarchive(void* a_data, size_t a_size)
  : m_data(a_data)
  , m_size(a_size)
{
  char* data = reinterpret_cast<char*>(m_data);
  xdrmem_create(&m_xdr, data, m_size, XDR_DECODE);
}

iarchive::~iarchive()
{
  xdr_destroy(&m_xdr);
}

bool
iarchive::operator()(bool& a_value)
{
  bool_t value;
  int code = xdr_bool(&m_xdr, &value);
  a_value = value ? true : false;
  return static_cast<bool>(code);
}

bool
iarchive::operator()(char& a_value)
{
  return xdr_char(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::int8_t& a_value)
{
  char value;
  int code = xdr_char(&m_xdr, &value);
  a_value = static_cast<std::int8_t>(value);
  return static_cast<bool>(code);
}

bool
iarchive::operator()(std::int16_t& a_value)
{
  return xdr_short(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::int32_t& a_value)
{
  return xdr_int(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::int64_t& a_value)
{
  return xdr_hyper(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::uint8_t& a_value)
{
  unsigned char value;
  int code = xdr_u_char(&m_xdr, &value);
  a_value = static_cast<std::uint8_t>(value);
  return static_cast<bool>(code);
}

bool
iarchive::operator()(std::uint16_t& a_value)
{
  return xdr_u_short(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::uint32_t& a_value)
{
  return xdr_u_int(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::uint64_t& a_value)
{
  return xdr_u_hyper(&m_xdr, &a_value);
}

bool
iarchive::operator()(float& a_value)
{
  return xdr_float(&m_xdr, &a_value);
}

bool
iarchive::operator()(double& a_value)
{
  return xdr_double(&m_xdr, &a_value);
}

bool
iarchive::operator()(std::string& a_value)
{
  std::uint32_t l_value;
  u_int pos = xdr_getpos(&m_xdr);
  int code = xdr_u_int(&m_xdr, &l_value);
  if (code == 0 || l_value > SIZE_LIMIT)
  {
    return false;
  }
  a_value.resize(l_value);
  code = xdr_setpos(&m_xdr, pos);
  char* p_value = const_cast<char*>(a_value.data());
  code = xdr_string(&m_xdr, &p_value, SIZE_LIMIT + 1);
  return static_cast<bool>(code);
}

bool
iarchive::operator()(std::vector<bool>& a_vector)
{
  bool b;
  std::uint32_t n;
  std::uint32_t l_vector;
  int code = xdr_u_int(&m_xdr, &l_vector);
  if (code == 0 || l_vector > SIZE_LIMIT)
  {
    return false;
  }
  a_vector.resize(l_vector);
  for (n = 0; n < l_vector; ++n)
  {
    code &= operator()(b);
    a_vector[n] = b;
  }
  return code;
}

oarchive::oarchive(size_t a_size)
  : m_size(a_size)
{
  m_data = malloc(m_size);
  char* data = reinterpret_cast<char*>(m_data);
  xdrmem_create(&m_xdr, data, m_size, XDR_ENCODE);
}

oarchive::~oarchive()
{
  xdr_destroy(&m_xdr);
}

void*
oarchive::data() const
{
  return m_data;
}

size_t
oarchive::size() const
{
  return m_size;
}

bool
oarchive::operator()(bool a_value)
{
  bool_t value = a_value ? TRUE : FALSE;
  return xdr_bool(&m_xdr, &value);
}

bool
oarchive::operator()(char a_value)
{
  return xdr_char(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::int8_t a_value)
{
  char value = static_cast<char>(a_value);
  return xdr_char(&m_xdr, &value);
}

bool
oarchive::operator()(std::int16_t a_value)
{
  return xdr_short(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::int32_t a_value)
{
  return xdr_int(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::int64_t a_value)
{
  return xdr_hyper(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::uint8_t a_value)
{
  unsigned char value = static_cast<unsigned char>(a_value);
  return xdr_u_char(&m_xdr, &value);
}

bool
oarchive::operator()(std::uint16_t a_value)
{
  return xdr_u_short(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::uint32_t a_value)
{
  return xdr_u_int(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::uint64_t a_value)
{
  return xdr_u_hyper(&m_xdr, &a_value);
}

bool
oarchive::operator()(float a_value)
{
  return xdr_float(&m_xdr, &a_value);
}

bool
oarchive::operator()(double a_value)
{
  return xdr_double(&m_xdr, &a_value);
}

bool
oarchive::operator()(std::string& a_value)
{
  char* p_value = const_cast<char*>(a_value.data());
  return xdr_string(&m_xdr, &p_value, 65535);
}

bool
oarchive::operator()(const std::string& a_value)
{
  return operator()(const_cast<std::string&>(a_value));
}

bool
oarchive::operator()(std::vector<bool>& a_vector)
{
  bool b;
  std::uint32_t n;
  std::uint32_t l_vector = a_vector.size();
  int code = xdr_u_int(&m_xdr, &l_vector);
  for (n = 0; n < l_vector; ++n)
  {
    b = a_vector[n];
    code &= operator()(b);
  }
  return code;
}

bool
oarchive::operator()(const std::vector<bool>& a_vector)
{
  return operator()(const_cast<std::vector<bool>&>(a_vector));
}

size_t
archive_sizer::operator()(bool a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(char a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::int8_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::int16_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::int32_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::int64_t a_value)
{
  return 8;
}

size_t
archive_sizer::operator()(std::uint8_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::uint16_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::uint32_t a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(std::uint64_t a_value)
{
  return 8;
}

size_t
archive_sizer::operator()(float a_value)
{
  return 4;
}

size_t
archive_sizer::operator()(double a_value)
{
  return 8;
}

size_t
archive_sizer::operator()(std::string& a_value)
{
  return 4 + 4 * ((a_value.size() + 3) / 4);
}

size_t
archive_sizer::operator()(const std::string& a_value)
{
  return operator()(const_cast<std::string&>(a_value));
}

size_t
archive_sizer::operator()(std::vector<bool>& a_vector)
{
  return 4 + 4 * a_vector.size();
}

size_t
archive_sizer::operator()(const std::vector<bool>& a_vector)
{
  return operator()(const_cast<std::vector<bool>&>(a_vector));
}

} // hermes namespace
