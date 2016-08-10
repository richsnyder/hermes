#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace state {

const std::set<space>&
blueprint::spaces() const
{
  return m_spaces;
}

const std::set<constant>&
blueprint::constants() const
{
  return m_constants;
}

const std::set<interface>&
blueprint::interfaces() const
{
  return m_interfaces;
}

const std::set<std::shared_ptr<enumeration>>&
blueprint::enumerations() const
{
  return m_enumerations;
}

const std::set<std::shared_ptr<structure>>&
blueprint::structures() const
{
  return m_structures;
}

const std::set<std::shared_ptr<exception>>&
blueprint::exceptions() const
{
  return m_exceptions;
}

const std::vector<std::shared_ptr<alias>>&
blueprint::aliases() const
{
  return m_aliases;
}

blueprint::pointer
blueprint::find(const std::string& a_name) const
{
  {
    auto pred = has_name<alias>(a_name);
    auto match = std::find_if(m_aliases.begin(), m_aliases.end(), pred);
    if (match != m_aliases.end())
    {
      return *match;
    }
  }

  {
    auto pred = has_name<structure>(a_name);
    auto match = std::find_if(m_structures.begin(), m_structures.end(), pred);
    if (match != m_structures.end())
    {
      return *match;
    }
  }

  {
    auto pred = has_name<exception>(a_name);
    auto match = std::find_if(m_exceptions.begin(), m_exceptions.end(), pred);
    if (match != m_exceptions.end())
    {
      return *match;
    }
  }

  {
    auto pred = has_name<enumeration>(a_name);
    auto match = std::find_if(m_enumerations.begin(),m_enumerations.end(),pred);
    if (match != m_enumerations.end())
    {
      return *match;
    }
  }

  return nullptr;
}

std::string
blueprint::get_space(const std::string& a_name) const
{
  auto pred = [&](const space& s) { return s.name() == a_name; };
  auto iter = std::find_if(m_spaces.begin(), m_spaces.end(), pred);
  return (iter == m_spaces.end()) ? std::string() : iter->value();
}

std::string
blueprint::token()
{
  std::string tok = m_tokens.top();
  m_tokens.pop();
  return tok;
}

void
blueprint::token(const std::string& a_identifier)
{
  m_tokens.push(a_identifier);
}

blueprint::pointer
blueprint::datatype()
{
  pointer ptr = m_datatypes.top();
  m_datatypes.pop();
  return ptr;
}

void
blueprint::datatype(pointer a_datatype)
{
  m_datatypes.push(std::move(a_datatype));
}

void
blueprint::make_alias()
{
  m_aliases.push_back(std::make_shared<alias>(token(), datatype()));
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_constant()
{
  std::string str = token();
  pointer ptr = datatype();
  constant::value_type value;
  if (ptr->is_bool())
  {
    value = (str == "true") ? true : false;
  }
  else if (ptr->is_char())
  {
    value = str[0];
  }
  else if (ptr->is_int8())
  {
    value = static_cast<std::int8_t>(std::stol(str));
  }
  else if (ptr->is_int16())
  {
    value = static_cast<std::int16_t>(std::stol(str));
  }
  else if (ptr->is_int32())
  {
    value = static_cast<std::int32_t>(std::stol(str));
  }
  else if (ptr->is_int64())
  {
    value = static_cast<std::int64_t>(std::stol(str));
  }
  else if (ptr->is_uint8())
  {
    value = static_cast<std::uint8_t>(std::stoul(str));
  }
  else if (ptr->is_uint16())
  {
    value = static_cast<std::uint16_t>(std::stoul(str));
  }
  else if (ptr->is_uint32())
  {
    value = static_cast<std::uint32_t>(std::stoul(str));
  }
  else if (ptr->is_uint64())
  {
    value = static_cast<std::uint64_t>(std::stoul(str));
  }
  else if (ptr->is_real32())
  {
    value = static_cast<float>(std::stod(str));
  }
  else if (ptr->is_real64())
  {
    value = static_cast<double>(std::stod(str));
  }
  else if (ptr->is_string())
  {
    value = str;
  }
  else
  {
    // ERROR
  }
  m_constants.emplace(token(), value);
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_enumeration()
{
  assert(!m_working_enumeration);
  m_working_enumeration = std::make_shared<enumeration>(token());
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_enumeration_item()
{
  assert(m_working_enumeration);
  enumeration::item::value_type value;
  if (m_tokens.size() == 2)
  {
    value = std::stoi(token());
  }
  m_working_enumeration->add(token(), value);
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_exception()
{
  assert(m_tokens.size() == m_datatypes.size() + 1);
  std::vector<field> fields;
  while (!m_datatypes.empty())
  {
    fields.emplace(fields.begin(), token(), datatype());
  }
  m_exceptions.insert(std::make_shared<exception>(token(), fields));
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_interface()
{
  assert(!m_working_interface);
  m_working_interface = std::make_shared<interface>(token());
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_map()
{
  pointer value = datatype();
  pointer key = datatype();
  m_datatypes.push(std::make_shared<map>(key, value));
}

void
blueprint::make_procedure()
{
  assert(m_working_interface);
  std::vector<field> parameters;
  std::vector<std::shared_ptr<exception>> exceptions;
  while (m_datatypes.size() > m_tokens.size())
  {
    exceptions.emplace_back(std::dynamic_pointer_cast<exception>(datatype()));
  }
  while (m_tokens.size() > 1)
  {
    parameters.emplace(parameters.begin(), token(), datatype());
  }
  m_working_interface->add(token(), datatype(), parameters, exceptions);
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_set()
{
  m_datatypes.push(std::make_shared<set>(datatype()));
}

void
blueprint::make_space()
{
  std::string value = token();
  std::string name = token();
  m_spaces.emplace(name, value);
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_structure()
{
  assert(m_tokens.size() == m_datatypes.size() + 1);
  std::vector<field> fields;
  while (!m_datatypes.empty())
  {
    fields.emplace(fields.begin(), token(), datatype());
  }
  m_structures.insert(std::make_shared<structure>(token(), fields));
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::make_vector()
{
  m_datatypes.push(std::make_shared<vector>(datatype()));
}

void
blueprint::store_enumeration()
{
  assert(m_working_enumeration);
  m_enumerations.insert(m_working_enumeration);
  m_working_enumeration.reset();
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

void
blueprint::store_interface()
{
  assert(m_working_interface);
  m_interfaces.insert(*m_working_interface);
  m_working_interface.reset();
  assert(m_tokens.empty());
  assert(m_datatypes.empty());
}

} // state namespace
} // compiler namespace
} // hermes namespace
