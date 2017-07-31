#include "clp.hpp"

namespace hermes {
namespace compiler {

clp::clp(int a_argc, char* a_argv[])
  : m_output()
  , m_command_line("Hermes command line tool", '=', HERMES_VERSION)
  , m_language_cpp("", "cpp", "C++")
  , m_language_fortran("", "fortran", "Fortran")
  , m_language_python("", "python", "Python")
  , m_import_paths("", "import-path", "import path", false, "-")
  , m_output_directory("", "destination", "output directory", false, ".", "-")
  , m_input_files("file", "input file(s)", true, "-")
  , m_python_use_numpy("", "numpy", "use numpy arrays instead of Python lists")
{
  m_command_line.setOutput(&m_output);
  m_command_line.add(m_language_cpp);
  m_command_line.add(m_language_fortran);
  m_command_line.add(m_language_python);
  m_command_line.add(m_import_paths);
  m_command_line.add(m_output_directory);
  m_command_line.add(m_input_files);
  m_command_line.add(m_python_use_numpy);
  m_command_line.parse(a_argc, a_argv);
}

bool
clp::cpp() const
{
  typedef TCLAP::SwitchArg type;
  return const_cast<type&>(m_language_cpp).getValue();
}

bool
clp::fortran() const
{
  typedef TCLAP::SwitchArg type;
  return const_cast<type&>(m_language_fortran).getValue();
}

bool
clp::python() const
{
  typedef TCLAP::SwitchArg type;
  return const_cast<type&>(m_language_python).getValue();
}

bool
clp::use_numpy() const
{
  typedef TCLAP::SwitchArg type;
  return const_cast<type&>(m_python_use_numpy).getValue();
}

std::vector<std::string>
clp::import_paths() const
{
  typedef TCLAP::MultiArg<std::string> type;
  auto import_paths = const_cast<type&>(m_import_paths).getValue();

  std::string::size_type pos;
  std::string::size_type sep;
  std::vector<std::string> paths = {"."};
  for (const auto& path : import_paths)
  {
    pos = 0;
    while (!path.empty())
    {
      sep = path.find(':', pos);
      if (sep == std::string::npos)
      {
        paths.push_back(path.substr(pos));
        break;
      }
      else
      {
        paths.push_back(path.substr(pos, sep - pos));
        pos = sep + 1;
      }
    }
  }
  return paths;
}

std::string
clp::output_directory() const
{
  typedef TCLAP::ValueArg<std::string> type;
  return const_cast<type&>(m_output_directory).getValue();
}

const std::vector<std::string>&
clp::input_files() const
{
  typedef TCLAP::UnlabeledMultiArg<std::string> type;
  return const_cast<type&>(m_input_files).getValue();
}

void
clp::output::failure(interface_type& a_interface, exception_type& a_exception)
{
  std::cout << a_exception.error() << std::endl;
  exit(1);
}

void
clp::output::usage(interface_type& a_interface)
{
  using std::cout;
  using std::endl;

  cout << "Usage: hermes [options] <file> ..." << endl << endl;
  cout << a_interface.getMessage() << endl << endl;
  cout << "General options:" << endl;
  cout << "  --cpp                 Generate C++ header and source." << endl;
  cout << "  --fortran             Generate Fortran source." << endl;
  cout << "  --python              Generate Python source." << endl;
  cout << "  --import-path=<dir>   Search path for import statements." << endl;
  cout << "  --destination=<dir>   Destination directory (default: current directory)." << endl;
  cout << "  --version             Display version information and exit." << endl;
  cout << "  -h, --help            Display this help text and exit." << endl;
  cout << endl << "Python options:" << endl;
  cout << "  --numpy               Use numpy arrays instead of lists." << endl;
  cout << endl << "Argument:" << endl;
  cout << "  <file>                Interface in the Hermes interface definition language." << endl;
}

void
clp::output::version(interface_type& a_interface)
{
  std::cout << "hermes, version " << a_interface.getVersion() << std::endl;
}

} // compiler namespace
} // hermes namespace
