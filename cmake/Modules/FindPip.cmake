# ==============================================================================
#
# Find the Pip Installs Packages package management system for Python
#
# ------------------------------------------------------------------------------
#
# Variables defined by this module include:
#   Pip_FOUND          TRUE if pip and all components are found
#   Pip_EXECUTABLE     Full path to the pip executable
#   Pip_VERSION        The version of the pip program
#
# ==============================================================================

INCLUDE(FindPackageHandleStandardArgs)

FIND_PROGRAM(Pip_EXECUTABLE NAMES pip)

IF(Pip_EXECUTABLE)
  EXECUTE_PROCESS(COMMAND ${Pip_EXECUTABLE} "--version"
      ERROR_VARIABLE Pip_VERSION
      OUTPUT_VARIABLE Pip_VERSION
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  STRING(REGEX
      REPLACE "^pip ([.0-9]+).*" "\\1"
      Pip_VERSION
      "${Pip_VERSION}")
ENDIF()

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    Pip
    FOUND_VAR Pip_FOUND
    REQUIRED_VARS Pip_EXECUTABLE
    VERSION_VAR Pip_VERSION)
