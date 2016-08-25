#ifndef HERMES_COMPILER_GENERATOR_FORTRAN_GENERATOR_HPP
#define HERMES_COMPILER_GENERATOR_FORTRAN_GENERATOR_HPP

#include <fstream>
#include <iomanip>
#include <set>
#include <string>
#include <vector>
#include "state/blueprint.hpp"
#include "generator/iomanip.hpp"
#include "generator/utilities.hpp"
#include "generator/fortran/sizevar.hpp"
#include "generator/fortran/translate.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace fortran {

class generator
{
public:
  generator();

  void open(const std::string& a_project, const std::string& a_directory);
  void write(const state::blueprint& a_blueprint);
  void close();
protected:
  typedef std::shared_ptr<datatype> pointer;
  typedef std::vector<state::field> field_vector;

  void write_header();
  void write_enumerations();
  void write_structure_types();
  void write_interface_types();
  void write_structure_interfaces();
  void write_interface_interfaces();
  void write_contains();
  void write_structure_constructors();
  void write_structure_methods();
  void write_client_methods();
  void write_server_methods();
  void write_footer();

  void structure_type(std::shared_ptr<state::structure> a_structure);
  void structure_interface(std::shared_ptr<state::structure> a_structure);
  void structure_procedures(std::shared_ptr<state::structure> a_structure);
  void client_type(const state::interface& a_interface);
  void client_methods(const state::interface& a_interface);
  void server_type(const state::interface& a_interface);
  void server_interfaces(const state::interface& a_interface);
  void server_interface(const std::string& a_interface,
                        const state::procedure& a_procedure);
  void server_methods(const state::interface& a_interface);

  std::string param(const std::string& a_variable) const;
  std::string member(const std::string& a_variable) const;
  std::string category(std::shared_ptr<state::datatype> a_datatype, bool a_input) const;
  void public_procedure(const std::string& a_type, const std::string& a_name);
  void private_procedure(const std::string& a_type, const std::string& a_name);
  void private_procedure(const std::string& a_name);
  void deferred_procedure(const std::string& a_type, const std::string& a_name);
  void private_member(const state::field& a_field);
  void private_member(const state::field& a_field, const std::string& a_suffix);
  void constructor(std::shared_ptr<state::structure> a_structure);
  void getter(const std::string& a_structure, const state::field& a_field);
  void setter(const std::string& a_structure, const state::field& a_field);
  void size(const std::string& a_structure, const state::field& a_field);
  void resizer(const std::string& a_structure, const state::field& a_field);
  void clearer(const std::string& a_structure, const state::field& a_field);
  void reader(std::shared_ptr<state::structure> a_structure);
  void writer(std::shared_ptr<state::structure> a_structure);
  void archive(const field_vector& a_fields, bool a_input);
  void archive(const std::string& a_name, std::shared_ptr<state::datatype> a_type, bool a_input, bool a_first);
  void base_call(const std::string& a_interface, const state::procedure& a_procedure);
  void code_call(const std::string& a_interface, const state::procedure& a_procedure);
  void client_request(const std::string& a_interface, const state::procedure& a_procedure, int a_id);
  void client_catcher(const std::string& a_interface, std::shared_ptr<state::exception> a_exception, int a_id);
  void server_handler(const std::string& a_interface, const state::procedure& a_procedure);
  void server_request(const std::string& a_interface, const state::procedure& a_procedure);
  void server_throw(const std::string& a_interface, std::shared_ptr<state::exception> a_exception, int a_id);
  void server_throw_error(const state::interface& a_interface);
  void server_serve_once(const state::interface& a_interface);

  std::shared_ptr<sizer> get_size(const std::string& a_variable,
                                  pointer a_datatype) const;
  std::shared_ptr<sizer> get_size(const field_vector& a_fields) const;

  std::set<std::string> imports(std::shared_ptr<state::datatype> a_type) const;
  std::set<std::string> imports(std::shared_ptr<state::datatype> a_result, const field_vector& a_fields) const;
  std::set<std::string> symbols(std::shared_ptr<state::datatype> a_type) const;
  std::set<std::string> symbols(std::shared_ptr<state::datatype> a_result, const field_vector& a_fields) const;
private:
  std::string m_project;
  std::string m_src_path;
  std::ofstream m_src;
  const state::blueprint* m_blueprint;
};

} // fortran namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_FORTRAN_GENERATOR_HPP
