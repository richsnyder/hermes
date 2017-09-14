#ifndef HERMES_COMPILER_GENERATOR_CPP_BASIC_HPP
#define HERMES_COMPILER_GENERATOR_CPP_BASIC_HPP

#include "generator/iomanip.hpp"
#include "generator/cpp/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class basic : public datatype
{
public:
  basic() = delete;
  basic(const basic&) = delete;
  basic& operator=(const basic&) = delete;

  std::string param_type() const;
protected:
  basic(const std::string& a_name);
};

class void_t : public basic
{
public:
  void_t();
  void_t(const void_t&) = delete;
  void_t& operator=(const void_t&) = delete;
};

class bool_t : public basic
{
public:
  bool_t();
  bool_t(const bool_t&) = delete;
  bool_t& operator=(const bool_t&) = delete;
};

class char_t : public basic
{
public:
  char_t();
  char_t(const char_t&) = delete;
  char_t& operator=(const char_t&) = delete;
};

class int8 : public basic
{
public:
  int8();
  int8(const int8&) = delete;
  int8& operator=(const int8&) = delete;
};

class int16 : public basic
{
public:
  int16();
  int16(const int16&) = delete;
  int16& operator=(const int16&) = delete;
};

class int32 : public basic
{
public:
  int32();
  int32(const int32&) = delete;
  int32& operator=(const int32&) = delete;
};

class int64 : public basic
{
public:
  int64();
  int64(const int64&) = delete;
  int64& operator=(const int64&) = delete;
};

class uint8 : public basic
{
public:
  uint8();
  uint8(const uint8&) = delete;
  uint8& operator=(const uint8&) = delete;
};

class uint16 : public basic
{
public:
  uint16();
  uint16(const uint16&) = delete;
  uint16& operator=(const uint16&) = delete;
};

class uint32 : public basic
{
public:
  uint32();
  uint32(const uint32&) = delete;
  uint32& operator=(const uint32&) = delete;
};

class uint64 : public basic
{
public:
  uint64();
  uint64(const uint64&) = delete;
  uint64& operator=(const uint64&) = delete;
};

class real32 : public basic
{
public:
  real32();
  real32(const real32&) = delete;
  real32& operator=(const real32&) = delete;
};

class real64 : public basic
{
public:
  real64();
  real64(const real64&) = delete;
  real64& operator=(const real64&) = delete;
};

class string : public basic
{
public:
  string();
  string(const string&) = delete;
  string& operator=(const string&) = delete;

  std::string param_type() const;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_BASIC_HPP
