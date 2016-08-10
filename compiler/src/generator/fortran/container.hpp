#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_CONTAINER_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_CONTAINER_HPP

#include <algorithm>
#include "generator/fortran/datatype.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class container : public datatype
{
public:
  container() = default;
  container(const container&) = delete;
  container& operator=(const container&) = delete;
};

class map : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  map() = delete;
  map(map&&) = delete;
  map(const map &) = delete;
  map& operator=(map&&) = delete;
  map& operator=(const map&) = delete;
  map(pointer a_key_type, pointer a_value_type);

  std::string in() const;
  std::string out() const;
  std::set<std::string> iso_c_symbols() const;
  std::set<std::string> structures() const;
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
  set(set&&) = delete;
  set(const set &) = delete;
  set& operator=(set&&) = delete;
  set& operator=(const set&) = delete;
  set(pointer a_key_type);

  std::string in() const;
  std::string out() const;
  bool allocatable() const;
  std::set<std::string> iso_c_symbols() const;
  std::set<std::string> structures() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_key_type;
};

class vector : public container
{
public:
  typedef std::shared_ptr<datatype> pointer;

  vector() = delete;
  vector(vector&&) = delete;
  vector(const vector &) = delete;
  vector& operator=(vector&&) = delete;
  vector& operator=(const vector&) = delete;
  vector(pointer a_value_type);

  std::string in() const;
  std::string out() const;
  bool allocatable() const;
  std::set<std::string> iso_c_symbols() const;
  std::set<std::string> structures() const;
  std::shared_ptr<sizer> size(const std::string& a_variable) const;
private:
  pointer m_value_type;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_CONTAINER_HPP
