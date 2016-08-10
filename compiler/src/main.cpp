#include <iostream>
#include <vector>
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

  try
  {
    hermes::compiler::clp program_options(a_argc, a_argv);
    language_cpp = program_options.cpp();
    language_fortran = program_options.fortran();
    language_python = program_options.python();
    output_directory = program_options.output_directory();
    input_files = program_options.input_files();
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
      hermes::compiler::state::blueprint blueprint;
      hermes::compiler::parser::file_parser parser(file);
      parser.parse<grammar, action, control>(blueprint);
      std::string stem = hermes::compiler::generator::stem(file);

      if (language_cpp)
      {
        generate("cpp", stem, output_directory, blueprint);
      }
      if (language_fortran)
      {
        generate("fortran", stem, output_directory, blueprint);
      }
      if (language_python)
      {
        generate("python", stem, output_directory, blueprint);
      }
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
