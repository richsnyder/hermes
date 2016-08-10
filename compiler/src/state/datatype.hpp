#ifndef HERMES_COMPILER_STATE_DATATYPE_HPP
#define HERMES_COMPILER_STATE_DATATYPE_HPP

#include <string>

namespace hermes {
namespace compiler {
namespace state {

class datatype
{
public:
  datatype() = delete;
  datatype(const datatype&) = delete;
  datatype& operator=(const datatype&) = delete;

  std::string name() const;

  virtual bool is_alias() const;
  virtual bool is_basic() const;
  virtual bool is_container() const;
  virtual bool is_enumeration() const;
  virtual bool is_exception() const;
  virtual bool is_structure() const;

  virtual bool is_bool() const;
  virtual bool is_char() const;
  virtual bool is_int8() const;
  virtual bool is_int16() const;
  virtual bool is_int32() const;
  virtual bool is_int64() const;
  virtual bool is_uint8() const;
  virtual bool is_uint16() const;
  virtual bool is_uint32() const;
  virtual bool is_uint64() const;
  virtual bool is_real32() const;
  virtual bool is_real64() const;
  virtual bool is_string() const;
  virtual bool is_void() const;

  virtual bool is_map() const;
  virtual bool is_set() const;
  virtual bool is_vector() const;

  virtual bool is_signed() const;
  virtual bool is_unsigned() const;
  virtual bool is_real() const;
protected:
  datatype(const std::string& a_name);
private:
  std::string m_name;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_DATATYPE_HPP
