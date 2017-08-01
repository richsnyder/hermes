#ifndef HERMES_COMPILER_STATE_ACTION_HPP
#define HERMES_COMPILER_STATE_ACTION_HPP

#include "parser/grammar.hpp"
#include "state/basic.hpp"
#include "state/blueprint.hpp"
#include "state/import_action.hpp"

namespace hermes {
namespace compiler {
namespace state {

template <typename Rule>
class action : parser::nothing<Rule> {};

template <>
struct action<parser::basic::void_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<void_t>());
  }
};

template <>
struct action<parser::basic::bool_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<bool_t>());
  }
};

template <>
struct action<parser::basic::char_t>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<char_t>());
  }
};

template <>
struct action<parser::basic::int8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int8>());
  }
};

template <>
struct action<parser::basic::int16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int16>());
  }
};

template <>
struct action<parser::basic::int32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int32>());
  }
};

template <>
struct action<parser::basic::int64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<int64>());
  }
};

template <>
struct action<parser::basic::uint8>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint8>());
  }
};

template <>
struct action<parser::basic::uint16>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint16>());
  }
};

template <>
struct action<parser::basic::uint32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint32>());
  }
};

template <>
struct action<parser::basic::uint64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<uint64>());
  }
};

template <>
struct action<parser::basic::real32>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<real32>());
  }
};

template <>
struct action<parser::basic::real64>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<real64>());
  }
};

template <>
struct action<parser::basic::string>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(std::make_shared<string>());
  }
};

template <>
struct action<parser::pair::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_pair();
  }
};

template <>
struct action<parser::map::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_map();
  }
};

template <>
struct action<parser::set::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_set();
  }
};

template <>
struct action<parser::vector::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.make_vector();
  }
};

template <>
struct action<parser::handle>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    a_blueprint.type(a_blueprint.find(a_input.string()));
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
struct action<parser::import::end>
{
  static void apply(const parser::input& a_input, blueprint& a_blueprint)
  {
    auto filename = a_blueprint.filename();
    parser::file_parser parser_(filename);
    auto import = std::make_shared<blueprint>();
    parser_.parse<parser::grammar, import_action, parser::control>(*import);
    a_blueprint.make_import(filename, import);
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
