#include <iostream>
#include <vector>
#include "json/json.hpp"
#include "generator/generate.hpp"
#include "parser/control.hpp"
#include "parser/grammar.hpp"
#include "state/action.hpp"
#include "clp.hpp"

int main(int a_argc, char* a_argv[])
{
  bool language_cpp;
  bool language_fortran;
  bool language_python;
  std::string output_directory;
  std::vector<std::string> input_files;
  std::vector<std::string> import_paths;
  nlohmann::json language_options;

  try
  {
    hermes::compiler::clp program_options(a_argc, a_argv);
    language_cpp = program_options.cpp();
    language_fortran = program_options.fortran();
    language_python = program_options.python();
    import_paths = program_options.import_paths();
    output_directory = program_options.output_directory();
    input_files = program_options.input_files();

    language_options = {
      {"cpp", {}},
      {"fortran", {}},
      {"python", {{"numpy", program_options.use_numpy()}}}
    };
  }
  catch (TCLAP::ArgException& e)
  {
    std::cerr << e.error() << std::endl;
  }

  try
  {
    using hermes::compiler::parser::grammar;
    using hermes::compiler::state::action;
    using hermes::compiler::parser::control;
    using hermes::compiler::generator::generate;

    for (auto file : input_files)
    {
      hermes::compiler::state::blueprint blueprint(import_paths);
      hermes::compiler::parser::file_parser parser(file);
      parser.parse<grammar, action, control>(blueprint);
      std::string stem = hermes::compiler::generator::stem(file);
      nlohmann::json opts;

      if (language_cpp)
      {
        opts = language_options["cpp"];
        generate("cpp", opts, stem, output_directory, blueprint);
      }
      if (language_fortran)
      {
        opts = language_options["fortran"];
        generate("fortran", opts, stem, output_directory, blueprint);
      }
      if (language_python)
      {
        opts = language_options["python"];
        generate("python", opts, stem, output_directory, blueprint);
      }
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
