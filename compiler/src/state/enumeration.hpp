#ifndef HERMES_COMPILER_STATE_ENUMERATION_HPP
#define HERMES_COMPILER_STATE_ENUMERATION_HPP

#include <memory>
#include <vector>
#include <boost/optional.hpp>
#include "state/datatype.hpp"

namespace hermes {
namespace compiler {
namespace state {

class enumeration : public datatype
{
public:
  class item
  {
  public:
    typedef boost::optional<int> value_type;

    item() = delete;
    item(item&&) = default;
    item(const item&) = delete;
    item& operator=(item&&) = default;
    item& operator=(const item&) = delete;
    item(const std::string& a_name, const value_type& a_value);

    std::string name() const;
    value_type value() const;
  private:
    std::string m_name;
    value_type m_value;
  };

  enumeration() = delete;
  enumeration(const enumeration&) = delete;
  enumeration& operator=(const enumeration&) = delete;
  enumeration(const std::string& a_name);

  bool is_enumeration() const;

  const std::vector<item>& items() const;

  void add(const std::string& a_name, const item::value_type& a_value);
private:
  std::vector<item> m_items;
};

} // state namespace
} // compiler namespace
} // hermes namespace

namespace std {

template <>
struct less<std::shared_ptr<hermes::compiler::state::enumeration>>
{
  using enumeration = hermes::compiler::state::enumeration;
  using pointer = std::shared_ptr<enumeration>;

  bool operator()(const pointer lhs, const pointer rhs) const
  {
    return lhs->name() < rhs->name();
  }
};

} // std namespace

#endif // HERMES_COMPILER_STATE_ENUMERATION_HPP
