#include "state/io.hpp"

namespace hermes {
namespace compiler {
namespace state {

std::ostream&
operator<<(std::ostream& a_out, const alias& a_alias)
{
  a_out << a_alias.name();
  auto p = a_alias.type();
  while (p->is_alias())
  {
    a_out << " -> " << p->name();
    p = std::dynamic_pointer_cast<alias>(p)->type();
  }
  a_out << " -> " << p->name();
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const blueprint& a_blueprint)
{
  a_out << "SPACES" << std::endl;
  for (const auto& x : a_blueprint.spaces())
  {
      a_out << " * " << x << std::endl;
  }
  a_out << std::endl;

  a_out << "ALIASES" << std::endl;
  for (const auto& x : a_blueprint.aliases())
  {
    a_out << "  * " << *x << std::endl;
  }
  a_out << std::endl;

  a_out << "CONSTANTS" << std::endl;
  for (const auto& x : a_blueprint.constants())
  {
    a_out << "  * " << x << std::endl;
  }
  a_out << std::endl;

  a_out << "ENUMERATIONS" << std::endl;
  for (const auto& x : a_blueprint.enumerations())
  {
    a_out << "  * " << *x << std::endl;
  }
  a_out << std::endl;

  a_out << "STRUCTURES" << std::endl;
  for (const auto& x : a_blueprint.structures())
  {
    a_out << "  * " << *x << std::endl;
  }
  a_out << std::endl;

  a_out << "EXCEPTIONS" << std::endl;
  for (const auto& x : a_blueprint.exceptions())
  {
    a_out << "  * " << *x << std::endl;
  }
  a_out << std::endl;

  a_out << "INTERFACES" << std::endl;
  for (const auto& x : a_blueprint.interfaces())
  {
    a_out << "  * " << x << std::endl;
  }

  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const constant& a_constant)
{
  a_out << a_constant.type()->name();
  a_out << " " << a_constant.name();
  a_out << " = " << a_constant.value();
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const enumeration& a_enumeration)
{
  a_out << a_enumeration.name() << " { ";
  bool is_first = true;
  for (const auto& item : a_enumeration.items())
  {
    if (is_first)
    {
      is_first = false;
    }
    else
    {
      a_out << ", ";
    }
    a_out << item.name();
    if (item.value())
    {
      a_out << " = " << *item.value();
    }
  }
  a_out << " }";
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const field& a_field)
{
  a_out << a_field.type()->name();
  a_out << " " << a_field.name();
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const interface& a_interface)
{
  a_out << a_interface.name() << std::endl;
  for (const auto& procedure : a_interface.procedures())
  {
    a_out << "      - " << procedure << std::endl;
  }
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const procedure& a_procedure)
{
  a_out << a_procedure.result()->name();
  a_out << " " << a_procedure.name() << " ( ";
  bool is_first = true;
  for (const auto& parameter : a_procedure.parameters())
  {
    if (is_first)
    {
      is_first = false;
    }
    else
    {
      a_out << ", ";
    }
    a_out << parameter.type()->name();
    a_out << " " << parameter.name();
  }
  a_out << " )";
  if (!a_procedure.exceptions().empty())
  {
    a_out << " throws ";
    bool is_first = true;
    for (const auto& exception : a_procedure.exceptions())
    {
      if (is_first)
      {
        is_first = false;
      }
      else
      {
        a_out << ", ";
      }
      a_out << exception->name();
    }
  }
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const space& a_space)
{
  a_out << a_space.name();
  a_out << " = " << a_space.value();
  return a_out;
}

std::ostream&
operator<<(std::ostream& a_out, const structure& a_structure)
{
  bool is_first = true;
  a_out << a_structure.name() << " { ";
  for (const auto& field : a_structure.fields())
  {
    if (is_first)
    {
      is_first = false;
    }
    else
    {
      a_out << ", ";
    }
    a_out << field;
  }
  a_out << " }";
  return a_out;
}

} // state namespace
} // compiler namespace
} // hermes namespace
