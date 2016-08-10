#ifndef HERMES_COMPILER_STATE_BASIC_HPP
#define HERMES_COMPILER_STATE_BASIC_HPP

#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

class basic : public datatype
{
public:
  basic() = delete;
  basic(const basic&) = delete;
  basic& operator=(const basic&) = delete;

  bool is_basic() const;
protected:
  basic(const std::string& a_name);
};

struct void_t : public basic
{
  void_t();
  void_t(const void_t&) = delete;
  void_t& operator=(const void_t&) = delete;

  bool is_void() const;
};

struct bool_t : public basic
{
  bool_t();
  bool_t(const bool_t&) = delete;
  bool_t& operator=(const bool_t&) = delete;

  bool is_bool() const;
};

struct char_t : public basic
{
  char_t();
  char_t(const char_t&) = delete;
  char_t& operator=(const char_t&) = delete;

  bool is_char() const;
};

struct int8 : public basic
{
  int8();
  int8(const int8&) = delete;
  int8& operator=(const int8&) = delete;

  bool is_int8() const;
};

struct int16 : public basic
{
  int16();
  int16(const int16&) = delete;
  int16& operator=(const int16&) = delete;

  bool is_int16() const;
};

struct int32 : public basic
{
  int32();
  int32(const int32&) = delete;
  int32& operator=(const int32&) = delete;

  bool is_int32() const;
};

struct int64 : public basic
{
  int64();
  int64(const int64&) = delete;
  int64& operator=(const int64&) = delete;

  bool is_int64() const;
};

struct uint8 : public basic
{
  uint8();
  uint8(const uint8&) = delete;
  uint8& operator=(const uint8&) = delete;

  bool is_uint8() const;
};

struct uint16 : public basic
{
  uint16();
  uint16(const uint16&) = delete;
  uint16& operator=(const uint16&) = delete;

  bool is_uint16() const;
};

struct uint32 : public basic
{
  uint32();
  uint32(const uint32&) = delete;
  uint32& operator=(const uint32&) = delete;

  bool is_uint32() const;
};

struct uint64 : public basic
{
  uint64();
  uint64(const uint64&) = delete;
  uint64& operator=(const uint64&) = delete;

  bool is_uint64() const;
};

struct real32 : public basic
{
  real32();
  real32(const real32&) = delete;
  real32& operator=(const real32&) = delete;

  bool is_real32() const;
};

struct real64 : public basic
{
  real64();
  real64(const real64&) = delete;
  real64& operator=(const real64&) = delete;

  bool is_real64() const;
};

struct string : public basic
{
  string();
  string(const string&) = delete;
  string& operator=(const string&) = delete;

  bool is_string() const;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_BASIC_HPP
