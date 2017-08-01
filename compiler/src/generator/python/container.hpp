#ifndef HERMES_COMPILER_GENERATOR_PYTHON_CONTAINER_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_CONTAINER_HPP

#include <memory>
#include "generator/iomanip.hpp"
#include "generator/python/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

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

  std::string default_value() const;

  void pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy = false) const;
  void unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy = false) const;
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

  std::string default_value() const;

  void pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy = false) const;
  void unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy = false) const;
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

  std::string default_value() const;

  void pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy = false) const;
  void unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy = false) const;
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

  std::string default_value() const;

  void pack(std::ostream& a_out,
            const std::string& a_variable,
            bool a_numpy = false) const;
  void unpack(std::ostream& a_out,
              const std::string& a_variable,
              bool a_numpy = false) const;
private:
  pointer m_value_type;
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_CONTAINER_HPP
