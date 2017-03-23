#ifndef HERMES_COMPILER_CLP_HPP
#define HERMES_COMPILER_CLP_HPP

#include "tclap/CmdLine.h"
#include "version.hpp"

namespace hermes {
namespace compiler {

class clp
{
public:
  clp(int a_argc, char* a_argv[]);

  bool cpp() const;
  bool fortran() const;
  bool python() const;

  std::vector<std::string> import_paths() const;
  std::string output_directory() const;

  const std::vector<std::string>& input_files() const;
protected:
  class output : public TCLAP::StdOutput
  {
  public:
    typedef TCLAP::ArgException exception_type;
    typedef TCLAP::CmdLineInterface interface_type;

    virtual void failure(interface_type& c, exception_type& e);
    virtual void usage(interface_type& c);
    virtual void version(interface_type& c);
  };
private:
  output m_output;
  TCLAP::SwitchArg m_language_cpp;
  TCLAP::SwitchArg m_language_fortran;
  TCLAP::SwitchArg m_language_python;
  TCLAP::MultiArg<std::string> m_import_paths;
  TCLAP::ValueArg<std::string> m_output_directory;
  TCLAP::UnlabeledMultiArg<std::string> m_input_files;
  TCLAP::CmdLine m_command_line;
};

} // compiler namespace
} // hermes namespace

#endif // HERMES_COMPILER_CLP_HPP
