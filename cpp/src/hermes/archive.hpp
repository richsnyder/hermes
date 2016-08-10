#ifndef HERMES_ARCHIVE_HPP
#define HERMES_ARCHIVE_HPP

#include <cinttypes>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <rpc/types.h>
#include <rpc/xdr.h>

namespace hermes {

class iarchive
{
public:
  iarchive(void* a_data, size_t a_size);
  ~iarchive();

  bool operator()(bool& a_value);
  bool operator()(char& a_value);
  bool operator()(std::int8_t& a_value);
  bool operator()(std::int16_t& a_value);
  bool operator()(std::int32_t& a_value);
  bool operator()(std::int64_t& a_value);
  bool operator()(std::uint8_t& a_value);
  bool operator()(std::uint16_t& a_value);
  bool operator()(std::uint32_t& a_value);
  bool operator()(std::uint64_t& a_value);
  bool operator()(float& a_value);
  bool operator()(double& a_value);
  bool operator()(std::string& a_value);

  template <typename T, typename U>
  bool operator()(std::map<T, U>& a_map)
  {
    T key;
    U value;
    std::uint32_t n;
    std::uint32_t l_map;
    int code = xdr_u_int(&m_xdr, &l_map);
    if (code == 0 || l_map > 65535)
    {
      return false;
    }
    for (n = 0; n < l_map; ++n)
    {
      code &= operator()(key);
      code &= operator()(value);
      a_map.insert(std::make_pair(key, value));
    }
    return code;
  }

  template <typename T>
  bool operator()(std::set<T>& a_set)
  {
    std::uint32_t n;
    std::uint32_t l_set;
    int code = xdr_u_int(&m_xdr, &l_set);
    if (code == 0 || l_set > 65535)
    {
      return false;
    }
    a_set.resize(l_set);
    for (n = 0; n < l_set; ++n)
    {
      code &= operator()(a_set[n]);
    }
    return code;
  }

  template <typename T>
  bool operator()(std::vector<T>& a_vector)
  {
    std::uint32_t n;
    std::uint32_t l_vector;
    int code = xdr_u_int(&m_xdr, &l_vector);
    if (code == 0 || l_vector > 65535)
    {
      return false;
    }
    a_vector.resize(l_vector);
    for (n = 0; n < l_vector; ++n)
    {
      code &= operator()(a_vector[n]);
    }
    return code;
  }

  template <typename T>
  bool operator()(T& a_object)
  {
    return a_object.read(*this);
  }
private:
  XDR m_xdr;
  void* m_data;
  size_t m_size;
};

class oarchive
{
public:
  oarchive(size_t a_size);
  ~oarchive();

  void* data() const;
  size_t size() const;

  bool operator()(bool a_value);
  bool operator()(char a_value);
  bool operator()(std::int8_t a_value);
  bool operator()(std::int16_t a_value);
  bool operator()(std::int32_t a_value);
  bool operator()(std::int64_t a_value);
  bool operator()(std::uint8_t a_value);
  bool operator()(std::uint16_t a_value);
  bool operator()(std::uint32_t a_value);
  bool operator()(std::uint64_t a_value);
  bool operator()(float a_value);
  bool operator()(double a_value);
  bool operator()(std::string& a_value);
  bool operator()(const std::string& a_value);

  template <typename T, typename U>
  bool operator()(std::map<T, U>& a_map)
  {
    std::uint32_t l_map = a_map.size();
    int code = xdr_u_int(&m_xdr, &l_map);
    for (const auto& key_value : a_map)
    {
      code &= operator()(key_value.first);
      code &= operator()(key_value.second);
    }
    return code;
  }

  template <typename T>
  bool operator()(const T& a_object)
  {
    return operator()(const_cast<T&>(a_object));
  }

  template <typename T>
  bool operator()(std::set<T>& a_set)
  {
    std::uint32_t n;
    std::uint32_t l_set = a_set.size();
    int code = xdr_u_int(&m_xdr, &l_set);
    for (n = 0; n < l_set; ++n)
    {
      code &= operator()(a_set[n]);
    }
    return code;
  }

  template <typename T, typename U>
  bool operator()(const std::map<T, U>& a_map)
  {
    return operator()(const_cast<std::map<T, U>&>(a_map));
  }

  template <typename T>
  bool operator()(std::vector<T>& a_vector)
  {
    std::uint32_t n;
    std::uint32_t l_vector = a_vector.size();
    int code = xdr_u_int(&m_xdr, &l_vector);
    for (n = 0; n < l_vector; ++n)
    {
      code &= operator()(a_vector[n]);
    }
    return code;
  }

  template <typename T>
  bool operator()(const std::set<T>& a_set)
  {
    return operator()(const_cast<std::set<T>&>(a_set));
  }

  template <typename T>
  bool operator()(T& a_object)
  {
    return a_object.write(*this);
  }

  template <typename T>
  bool operator()(const std::vector<T>& a_vector)
  {
    return operator()(const_cast<std::vector<T>&>(a_vector));
  }
private:
  XDR m_xdr;
  void* m_data;
  size_t m_size;
};

} // hermes namespace

#endif // HERMES_ARCHIVE_HPP
