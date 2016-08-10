# ==============================================================================
#
# Find the Asciidoctor processor
#
# ------------------------------------------------------------------------------
#
# Variables defined by this module include:
#   Asciidoctor_FOUND          TRUE if Asciidoctor and all components are found
#   Asciidoctor_EXECUTABLE     Full path to the Asciidoctor executable
#   Asciidoctor_VERSION        The version of the Asciidoctor program
#
# ==============================================================================

INCLUDE(FindPackageHandleStandardArgs)

FIND_PROGRAM(Asciidoctor_EXECUTABLE NAMES asciidoctor)

IF(Asciidoctor_EXECUTABLE)
  EXECUTE_PROCESS(COMMAND ${Asciidoctor_EXECUTABLE} "--version"
      ERROR_VARIABLE Asciidoctor_VERSION
      OUTPUT_VARIABLE Asciidoctor_VERSION
      OUTPUT_STRIP_TRAILING_WHITESPACE)
  STRING(REGEX
      REPLACE "^Asciidoctor ([.0-9]+).*" "\\1"
      Asciidoctor_VERSION
      "${Asciidoctor_VERSION}")
ENDIF()

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
    Asciidoctor
    FOUND_VAR Asciidoctor_FOUND
    REQUIRED_VARS Asciidoctor_EXECUTABLE
    VERSION_VAR Asciidoctor_VERSION)
