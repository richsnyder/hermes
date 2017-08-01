#ifndef HERMES_COMPILER_GENERATOR_CPP_CONTAINER_HPP
#define HERMES_COMPILER_GENERATOR_CPP_CONTAINER_HPP

#include "generator/iomanip.hpp"
#include "generator/cpp/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class container : public datatype
{
public:
  container() = delete;
  container(const datatype &) = delete;
  container& operator=(const container&) = delete;
protected:
  container(const std::string& a_name);
};

class pair : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  pair() = delete;
  pair(const pair&) = delete;
  pair& operator=(const pair&) = delete;
  pair(pointer a_first_type, pointer a_second_type);

  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_first_type;
  pointer m_second_type;
};

class map : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  map() = delete;
  map(const map&) = delete;
  map& operator=(const map&) = delete;
  map(pointer a_key_type, pointer a_value_type);

  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_key_type;
  pointer m_value_type;
};

class set : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  set() = delete;
  set(const set&) = delete;
  set& operator=(const set&) = delete;
  set(pointer a_key_type);

  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_key_type;
};

class vector : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  vector() = delete;
  vector(const vector&) = delete;
  vector& operator=(const vector&) = delete;
  vector(pointer a_value_type);

  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_value_type;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_CONTAINER_HPP
