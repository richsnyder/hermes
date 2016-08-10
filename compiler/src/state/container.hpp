#ifndef HERMES_COMPILER_STATE_CONTAINER_HPP
#define HERMES_COMPILER_STATE_CONTAINER_HPP

#include <memory>
#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

class container : public datatype
{
public:
  container() = delete;
  container(const container&) = delete;
  container& operator=(const container&) = delete;

  bool is_container() const;
protected:
  container(const std::string& a_name);
};

class map : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  map() = delete;
  map(const map&) = delete;
  map& operator=(const map&) = delete;
  map(pointer a_key_type, pointer a_value_type);

  bool is_map() const;

  pointer key_type() const;
  pointer value_type() const;
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

  bool is_set() const;

  pointer key_type() const;
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

  bool is_vector() const;

  pointer value_type() const;
private:
  pointer m_value_type;
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_CONTAINER_HPP
