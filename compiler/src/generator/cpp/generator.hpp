#ifndef HERMES_COMPILER_GENERATOR_CPP_GENERATOR_HPP
#define HERMES_COMPILER_GENERATOR_CPP_GENERATOR_HPP

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "json/json.hpp"
#include "state/blueprint.hpp"
#include "generator/iomanip.hpp"
#include "generator/utilities.hpp"
#include "generator/cpp/sizevar.hpp"
#include "generator/cpp/translate.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace cpp {

class generator
{
public:
  generator(const nlohmann::json& a_options);

  void open(const std::string& a_project, const std::string& a_directory);
  void write(const state::blueprint& a_blueprint);
  void close();
protected:
  typedef std::shared_ptr<datatype> pointer;
  typedef std::vector<state::field> field_vector;

  void write_header();
  void write_enumerations();
  void write_forwards();
  void write_aliases();
  void write_structures();
  void write_constants();
  void write_interfaces();
  void write_footer();

  void write_enumeration(const state::enumeration& a_enumeration);
  void write_alias(const state::alias& a_alias);
  void write_structure(const state::structure& a_structure);
  void write_constant(const state::constant& a_constant);
  void write_interface(const state::interface& a_interface);

  char toguard(char a_char) const;
  std::string include_guard() const;
  std::vector<std::string> split_namespace() const;
  std::string param(const std::string& a_variable) const;
  std::string member(const std::string& a_variable) const;

  void parameters(std::ostream& a_out, const field_vector& a_fields);
  void references(std::ostream& a_out, const field_vector& a_fields);
  void arguments(std::ostream& a_out, const field_vector& a_fields);
  void variables(std::ostream& a_out, const field_vector& a_fields);
  void archive(std::ostream& a_out, const field_vector& a_fields);
  void initialization(std::ostream& a_out, const field_vector& a_fields);
  void empty_body(std::ostream& a_out);

  void forwards(std::shared_ptr<state::datatype> a_datatype,
                std::set<std::string>& a_forwards) const;
  std::shared_ptr<sizer> get_size(const std::string& a_variable,
                                  pointer a_datatype) const;
  std::shared_ptr<sizer> get_size(const field_vector& a_fields) const;

  void constructors(const state::structure& a_structure);
  void decoder(const state::structure& a_structure);
  void encoder(const state::structure& a_structure);
  void member(const state::field& a_field);
  void getter(const std::string& a_class, const state::field& a_field);
  void setter(const std::string& a_class, const state::field& a_field);
  void size(const std::string& a_class, const state::field& a_field);
  void resizer(const std::string& a_class, const state::field& a_field);
  void clearer(const std::string& a_class, const state::field& a_field);
  void map_getter(const std::string& a_class, const state::field& a_field);
  void map_inserter(const std::string& a_class, const state::field& a_field);
  void set_counter(const std::string& a_class, const state::field& a_field);
  void set_inserter(const std::string& a_class, const state::field& a_field);
  void vector_getter(const std::string& a_class, const state::field& a_field);
  void vector_setter(const std::string& a_class, const state::field& a_field);
  void vector_pusher(const std::string& a_class, const state::field& a_field);
  void client(const state::interface& a_interface);
  void server(const state::interface& a_interface);
  void rpc(const state::interface& a_interface);

  void client_procedure(const std::string& a_interface,
                        std::int32_t a_id,
                        const state::procedure& a_procedure);
  void server_procedure(std::int32_t a_id,
                        const state::procedure& a_procedure);
  void rpc_procedure(const std::string& a_interface,
                     std::int32_t a_id,
                     const state::procedure& a_procedure);
  void rpc_request(const std::string& a_interface,
                   const std::string& a_method,
                   const field_vector& a_parameters);
  void rpc_reply(const std::string& a_interface,
                 const std::string& a_method,
                 std::shared_ptr<state::datatype> a_result);
  void rpc_exception(const std::string& a_interface,
                     const std::string& a_method,
                     std::shared_ptr<state::exception> a_exception);
private:
  std::string m_project;
  std::string m_hpp_path;
  std::string m_cpp_path;
  std::string m_directory;
  std::ofstream m_hpp;
  std::ofstream m_cpp;
  const state::blueprint* m_blueprint;
};

} // cpp namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_CPP_GENERATOR_HPP
