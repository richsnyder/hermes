#ifndef HERMES_COMPILER_STATE_ACTION_HPP
#define HERMES_COMPILER_STATE_ACTION_HPP

#include "parser/grammar.hpp"
#include "state/basic.hpp"
#include "state/blueprint.hpp"

namespace hermes {
namespace compiler {
namespace state {

template <typename Rule>
class action : parser::nothing<Rule> {};

template <>
struct action<parser::datatype::basic::void_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<void_t>());
  }
};

template <>
struct action<parser::datatype::basic::bool_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<bool_t>());
  }
};

template <>
struct action<parser::datatype::basic::char_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<char_t>());
  }
};

template <>
struct action<parser::datatype::basic::int8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<int8>());
  }
};

template <>
struct action<parser::datatype::basic::int16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<int16>());
  }
};

template <>
struct action<parser::datatype::basic::int32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<int32>());
  }
};

template <>
struct action<parser::datatype::basic::int64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<int64>());
  }
};

template <>
struct action<parser::datatype::basic::uint8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<uint8>());
  }
};

template <>
struct action<parser::datatype::basic::uint16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<uint16>());
  }
};

template <>
struct action<parser::datatype::basic::uint32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<uint32>());
  }
};

template <>
struct action<parser::datatype::basic::uint64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<uint64>());
  }
};

template <>
struct action<parser::datatype::basic::real32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<real32>());
  }
};

template <>
struct action<parser::datatype::basic::real64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<real64>());
  }
};

template <>
struct action<parser::datatype::basic::string>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(std::make_shared<string>());
  }
};

template <>
struct action<parser::datatype::container::map::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_map();
  }
};

template <>
struct action<parser::datatype::container::set::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_set();
  }
};

template <>
struct action<parser::datatype::container::vector::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_vector();
  }
};

template <>
struct action<parser::datatype::handle>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.datatype(a_blueprint.find(a_input.string()));
  }
};

template <>
struct action<parser::identifier>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::unique_identifier>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::bool_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::char_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::int_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::real_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::string_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::uint_>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::alias::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_alias();
  }
};

template <>
struct action<parser::constant::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_constant();
  }
};

template <>
struct action<parser::enumeration::begin>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration();
  }
};

template <>
struct action<parser::enumeration::separator>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration_item();
  }
};

template <>
struct action<parser::enumeration::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_enumeration_item();
    a_blueprint.store_enumeration();
  }
};

template <>
struct action<parser::exception::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_exception();
  }
};

template <>
struct action<parser::interface::begin>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_interface();
  }
};

template <>
struct action<parser::interface::separator>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_procedure();
  }
};

template <>
struct action<parser::interface::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_procedure();
    a_blueprint.store_interface();
  }
};

template <>
struct action<parser::space::name>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.token(a_input.string());
  }
};

template <>
struct action<parser::space::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_space();
  }
};

template <>
struct action<parser::structure::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_structure();
  }
};

} // state namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_STATE_ACTION_HPP
