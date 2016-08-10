#include "generator/python/translate.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

std::shared_ptr<datatype>
translate(std::shared_ptr<state::datatype> a_datatype)
{
  if (a_datatype->is_alias())
  {
    auto as_alias = std::dynamic_pointer_cast<state::alias>(a_datatype);
    std::shared_ptr<datatype> root = translate(as_alias->root_type());
    return std::make_shared<alias>(root);
  }
  else if (a_datatype->is_enumeration())
  {
    return std::make_shared<enumeration>();
  }
  else if (a_datatype->is_exception())
  {
    std::vector<field> fields;
    auto as_exception = std::dynamic_pointer_cast<state::exception>(a_datatype);
    auto name = to_camel(as_exception->name());
    for (const auto& f : as_exception->fields())
    {
      std::shared_ptr<datatype> field_type = translate(f.type());
      fields.emplace_back(f.name(), field_type);
    }
    return std::make_shared<exception>(name, fields);
  }
  else if (a_datatype->is_structure())
  {
    std::vector<field> fields;
    auto as_structure = std::dynamic_pointer_cast<state::structure>(a_datatype);
    auto name = to_camel(as_structure->name());
    for (const auto& f : as_structure->fields())
    {
      std::shared_ptr<datatype> field_type = translate(f.type());
      fields.emplace_back(f.name(), field_type);
    }
    return std::make_shared<structure>(name, fields);
  }
  else if (a_datatype->is_bool())
  {
    return std::make_shared<bool_t>();
  }
  else if (a_datatype->is_char())
  {
    return std::make_shared<char_t>();
  }
  else if (a_datatype->is_int8())
  {
    return std::make_shared<int8>();
  }
  else if (a_datatype->is_int16())
  {
    return std::make_shared<int16>();
  }
  else if (a_datatype->is_int32())
  {
    return std::make_shared<int32>();
  }
  else if (a_datatype->is_int64())
  {
    return std::make_shared<int64>();
  }
  else if (a_datatype->is_uint8())
  {
    return std::make_shared<uint8>();
  }
  else if (a_datatype->is_uint16())
  {
    return std::make_shared<uint16>();
  }
  else if (a_datatype->is_uint32())
  {
    return std::make_shared<uint32>();
  }
  else if (a_datatype->is_uint64())
  {
    return std::make_shared<uint64>();
  }
  else if (a_datatype->is_real32())
  {
    return std::make_shared<real32>();
  }
  else if (a_datatype->is_real64())
  {
    return std::make_shared<real64>();
  }
  else if (a_datatype->is_string())
  {
    return std::make_shared<string>();
  }
  else if (a_datatype->is_void())
  {
  //   return std::make_shared<void_t>();
  }
  else if (a_datatype->is_map())
  {
    auto as_map = std::dynamic_pointer_cast<state::map>(a_datatype);
    std::shared_ptr<datatype> key_type = translate(as_map->key_type());
    std::shared_ptr<datatype> value_type = translate(as_map->value_type());
    return std::make_shared<map>(key_type, value_type);
  }
  else if (a_datatype->is_set())
  {
    auto as_set = std::dynamic_pointer_cast<state::set>(a_datatype);
    std::shared_ptr<datatype> key_type = translate(as_set->key_type());
    return std::make_shared<set>(key_type);
  }
  else if (a_datatype->is_vector())
  {
    auto as_vector = std::dynamic_pointer_cast<state::vector>(a_datatype);
    std::shared_ptr<datatype> value_type = translate(as_vector->value_type());
    return std::make_shared<vector>(value_type);
  }
  return nullptr;
}

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace
