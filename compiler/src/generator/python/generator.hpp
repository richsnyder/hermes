#ifndef HERMES_COMPILER_GENERATOR_PYTHON_GENERATOR_HPP
#define HERMES_COMPILER_GENERATOR_PYTHON_GENERATOR_HPP

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "state/blueprint.hpp"
#include "generator/iomanip.hpp"
#include "generator/utilities.hpp"
#include "generator/python/datatype.hpp"
#include "generator/python/translate.hpp"

namespace hermes {
namespace compiler {
namespace generator {
namespace python {

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
  void write_structures();
  void write_interfaces();

  void write_structure(const state::structure& a_structure);
  void write_interface(const state::interface& a_interface);

  void constructor(const field_vector& a_fields);
  void reader(const field_vector& a_fields);
  void writer(const field_vector& a_fields);
  void stringer(const field_vector& a_fields);
  void client(const state::interface& a_interface);
  void server(const state::interface& a_interface);
  void client_method(const state::procedure& a_procedure, int a_id);
  void server_method(const state::procedure& a_procedure, int a_id);

  // void write_enumerations();
  // void write_aliases();
  // void write_constants();
  // void write_interfaces();
private:
  std::string m_project;
  std::string m_py_path;
  std::ofstream m_py;
  const state::blueprint* m_blueprint;
};

} // python namespace
} // generator namespace
} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_GENERATOR_PYTHON_GENERATOR_HPP
