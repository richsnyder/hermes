#include "generator/fortran/structure.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

structure::structure(const std::string& a_name, const std::vector<field>& a_fields)
  : m_name(a_name)
  , m_fields(a_fields)
{
  // empty
}

std::string
structure::in() const
{
  return "type(" + m_name + ")";
}

std::set<std::string>
structure::structures() const
{
  return { m_name };
}

std::shared_ptr<sizer>
structure::size(const std::string& a_variable) const
{
  if (m_fields.empty())
  {
    return std::make_shared<sizer>("{}", 0);
  }

  std::string name;
  bool first = true;
  std::shared_ptr<sizer> root = nullptr;
  std::shared_ptr<sizer> next = nullptr;
  for (const auto& field_ : m_fields)
  {
    name = a_variable + "%get_" + field_.name() + "()";
    next = field_.type()->size(name);
    if (first)
    {
      root = next;
      first = false;
    }
    else
    {
      root->link(next);
    }
  }
  return root;
}

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
