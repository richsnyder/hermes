#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_BASIC_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_BASIC_HPP

#include "generator/iomanip.hpp"
#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class basic : public datatype
{
public:
  basic() = default;
  basic(const basic&) = delete;
  basic& operator=(const basic&) = delete;
};

class bool_t : public basic
{
public:
  bool_t() = default;
  bool_t(const bool_t&) = delete;
  bool_t& operator=(const bool_t&) = delete;

  std::string in() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class char_t : public basic
{
public:
  char_t() = default;
  char_t(const char_t&) = delete;
  char_t& operator=(const char_t&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class int8 : public basic
{
public:
  int8() = default;
  int8(const int8&) = delete;
  int8& operator=(const int8&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class int16 : public basic
{
public:
  int16() = default;
  int16(const int16&) = delete;
  int16& operator=(const int16&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class int32 : public basic
{
public:
  int32() = default;
  int32(const int32&) = delete;
  int32& operator=(const int32&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class int64 : public basic
{
public:
  int64() = default;
  int64(const int64&) = delete;
  int64& operator=(const int64&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class uint8 : public basic
{
public:
  uint8() = default;
  uint8(const uint8&) = delete;
  uint8& operator=(const uint8&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class uint16 : public basic
{
public:
  uint16() = default;
  uint16(const uint16&) = delete;
  uint16& operator=(const uint16&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class uint32 : public basic
{
public:
  uint32() = default;
  uint32(const uint32&) = delete;
  uint32& operator=(const uint32&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class uint64 : public basic
{
public:
  uint64() = default;
  uint64(const uint64&) = delete;
  uint64& operator=(const uint64&) = delete;

  std::string in() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class real32 : public basic
{
public:
  real32() = default;
  real32(const real32&) = delete;
  real32& operator=(const real32&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class real64 : public basic
{
public:
  real64() = default;
  real64(const real64&) = delete;
  real64& operator=(const real64&) = delete;

  std::string in() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

class string : public basic
{
public:
  string() = default;
  string(const string&) = delete;
  string& operator=(const string&) = delete;

  std::string in() const;
  std::string out() const;
  bool allocatable() const;
  std::set<std::string> iso_c_symbols() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_BASIC_HPP
