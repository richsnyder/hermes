#ifndef HERMES_COMPILER_STATE_IMPORT_ACTION_HPP
#define HERMES_COMPILER_STATE_IMPORT_ACTION_HPP

#include "parser/grammar.hpp"
#include "state/basic.hpp"
#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace state {

template <typename Rule>
class import_action : parser::nothing<Rule> {};

template <>
struct import_action<parser::basic::void_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<void_t>());
  }
};

template <>
struct import_action<parser::basic::bool_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<bool_t>());
  }
};

template <>
struct import_action<parser::basic::char_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<char_t>());
  }
};

template <>
struct import_action<parser::basic::int8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int8>());
  }
};

template <>
struct import_action<parser::basic::int16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int16>());
  }
};

template <>
struct import_action<parser::basic::int32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int32>());
  }
};

template <>
struct import_action<parser::basic::int64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int64>());
  }
};

template <>
struct import_action<parser::basic::uint8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint8>());
  }
};

template <>
struct import_action<parser::basic::uint16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint16>());
  }
};

template <>
struct import_action<parser::basic::uint32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint32>());
  }
};

template <>
struct import_action<parser::basic::uint64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint64>());
  }
};

template <>
struct import_action<parser::basic::real32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<real32>());
  }
};

template <>
struct import_action<parser::basic::real64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<real64>());
  }
};

template <>
struct import_action<parser::basic::string>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<string>());
  }
};

template <>
struct import_action<parser::pair::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_pair();
  }
};

template <>
struct import_action<parser::map::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_map();
  }
};

template <>
struct import_action<parser::set::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_set();
  }
};

template <>
struct import_action<parser::vector::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_vector();
  }
};

template <>
struct import_action<parser::handle>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(a_blueprint.find(a_input.string()));
  }
};

template <>
struct import_action<parser::identifier>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::unique_identifier>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::bool_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::char_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::int_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::real_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::string_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::uint_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::alias::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_alias();
  }
};

template <>
struct import_action<parser::constant::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_constant();
  }
};

template <>
struct import_action<parser::enumeration::begin>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration();
  }
};

template <>
struct import_action<parser::enumeration::separator>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration_item();
  }
};

template <>
struct import_action<parser::enumeration::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration_item();
    a_blueprint.store_enumeration();
  }
};

template <>
struct import_action<parser::exception::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_exception();
  }
};

template <>
struct import_action<parser::interface::begin>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_interface();
  }
};

template <>
struct import_action<parser::interface::separator>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_procedure();
  }
};

template <>
struct import_action<parser::interface::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_procedure();
    a_blueprint.store_interface();
  }
};

template <>
struct import_action<parser::space::name>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct import_action<parser::space::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_space();
  }
};

template <>
struct import_action<parser::structure::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_structure();
  }
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_IMPORT_ACTION_HPP
