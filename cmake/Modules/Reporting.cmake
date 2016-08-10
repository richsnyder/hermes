# ==============================================================================
#
# Reporting module for Hermes
#
# ------------------------------------------------------------------------------
#
# Functions for generating a configuration report for a Hermes build.
#
# ------------------------------------------------------------------------------
#
# This module defines the following functions:
#   YES_OR_NO()
#     - Converts a boolean to a "yes" or "no" string.
#   VERSION_OR_NOT_FOUND()
#     - Returns the version string of a package, or "not found".
#   CONFIGURATION_REPORT()
#     - Generates a report on the configuration for a Hermes build.
#
# ==============================================================================

INCLUDE(CMakeParseArguments)

# ------------------------------------------------------------------------------
#
# YES_OR_NO(<variable> <boolean>)
#
# Convert a boolean to a "yes" or "no" string.
#
# If <boolean> evaluates to true, then set <variable> to "yes".  Otherwise, set
# <variable> to "no".
#
# ------------------------------------------------------------------------------

FUNCTION(YES_OR_NO A_STRING A_BOOLEAN)

  IF(${A_BOOLEAN})
    SET(${A_STRING} "yes" PARENT_SCOPE)
  ELSE()
    SET(${A_STRING} "no" PARENT_SCOPE)
  ENDIF()

ENDFUNCTION(YES_OR_NO)

# ------------------------------------------------------------------------------
#
# VERSION_OR_NOT_FOUND(VAR <variable>
#                      [PACKAGE <package>]
#                      [FOUND <found>]
#                      [VERSION <version>])
#
# Set <variable> to the version number of a software package, or "not found".
#
# If <found> is defined and evaluates to true, then set <variable> to the value
# of <version>.  Otherwise, set <variable> to "not found".  If FOUND is not
# specified, then take <found> to be <package>_FOUND.  If VERSION is not
# specified, then take <version> to be <package>_VERSION.
#
# ------------------------------------------------------------------------------

FUNCTION(VERSION_OR_NOT_FOUND)

  # Parse the arguments to the function.
  CMAKE_PARSE_ARGUMENTS(A
    ""
    "VAR;PACKAGE;FOUND;VERSION"
    ""
    ${ARGN})

  # Make sure that all of the required arguments are present.
  IF(NOT DEFINED A_VAR)
    MESSAGE(FATAL_ERROR "An output variable is required")
  ENDIF()
  IF(NOT DEFINED A_PACKAGE AND NOT DEFINED A_FOUND)
    MESSAGE(FATAL_ERROR "Either FOUND or PACKAGE must be specified")
  ENDIF()
  IF(NOT DEFINED A_PACKAGE AND NOT DEFINED A_VERSION)
    MESSAGE(FATAL_ERROR "Either VERSION or PACKAGE must be specified")
  ENDIF()

  # Set the found and version variables based on the function arguments.
  IF(A_FOUND)
    SET(found ${${A_FOUND}})
  ELSE()
    SET(found ${${A_PACKAGE}_FOUND})
  ENDIF()
  IF(A_VERSION)
    SET(version ${${A_VERSION}})
  ELSE()
    SET(version ${${A_PACKAGE}_VERSION})
  ENDIF()

  # Set the output variable based on the found and version variables.
  IF(found)
    SET(${A_VAR} ${version} PARENT_SCOPE)
  ELSE()
    SET(${A_VAR} "not found" PARENT_SCOPE)
  ENDIF()

ENDFUNCTION(VERSION_OR_NOT_FOUND)

# ------------------------------------------------------------------------------
#
# COMPILER_LABEL(VAR <variable> LANGUAGE <language>)
#
# Set <variable> to a string that identifies the compiler for <language>.
#
# The output <variable> is set to a string that identifies the type of compiler
# for <language>, which must be one of C, CXX, or Fortran.  The string
# identifies the vendor, language, and version.
#
# ------------------------------------------------------------------------------

FUNCTION(COMPILER_LABEL)

  # Parse the arguments to the function.
  CMAKE_PARSE_ARGUMENTS(A
    ""
    "VAR;LANGUAGE"
    ""
    ${ARGN})

  # Make sure that all of the required arguments are present.
  IF(NOT DEFINED A_VAR)
    MESSAGE(FATAL_ERROR "An output variable is required")
  ENDIF()
  IF(NOT DEFINED A_LANGUAGE)
    MESSAGE(FATAL_ERROR "A compiler langauge must be specified")
  ENDIF()

  SET(id ${CMAKE_${A_LANGUAGE}_COMPILER_ID})
  SET(version ${CMAKE_${A_LANGUAGE}_COMPILER_VERSION})

  IF(id STREQUAL "Absoft")
    SET(name "Absoft")
  ELSEIF(id STREQUAL "ADSP")
    SET(name "Analog VisualDSP++")
  ELSEIF(id STREQUAL "AppleClang")
    SET(name "Apple Clang")
  ELSEIF(id STREQUAL "ARMCC")
    SET(name "ARM")
  ELSEIF(id STREQUAL "Bruce")
    SET(name "Bruce")
  ELSEIF(id STREQUAL "CCur")
    SET(name "Concurrent")
  ELSEIF(id STREQUAL "Clang")
    SET(name "LLVM Clang")
  ELSEIF(id STREQUAL "Cray")
    SET(name "Cray")
  ELSEIF(id STREQUAL "Embarcadero" OR id STREQUAL "Borland")
    SET(name "Embarcadero")
  ELSEIF(id STREQUAL "G95")
    SET(name "G95")
  ELSEIF(id STREQUAL "GNU")
    SET(name "GNU")
  ELSEIF(id STREQUAL "HP")
    SET(name "Hewlett-Packard")
  ELSEIF(id STREQUAL "Intel")
    SET(name "Intel")
  ELSEIF(id STREQUAL "MIPSpro")
    SET(name "SGI MIPSpro")
  ELSEIF(id STREQUAL "MSVC")
    SET(name "Microsoft Visual Studio")
  ELSEIF(id STREQUAL "OpenWatcom")
    SET(name "Open Watcom")
  ELSEIF(id STREQUAL "PGI")
    SET(name "Portland Group")
  ELSEIF(id STREQUAL "PathScale")
    SET(name "PathScale")
  ELSEIF(id STREQUAL "SDCC")
    SET(name "Small Device")
  ELSEIF(id STREQUAL "SunPro")
    SET(name "Oracle Solaris Studio")
  ELSEIF(id STREQUAL "TI")
    SET(name "Texas Instruments")
  ELSEIF(id STREQUAL "TinyCC")
    SET(name "Tiny")
  ELSEIF(id STREQUAL "XL" OR id STREQUAL "VisualAge" OR id STREQUAL "zOS")
    SET(name "IBM XL")
  ELSE()
    SET(name "Unknown")
  ENDIF()

  IF(${A_LANGUAGE} STREQUAL "C")
    SET(language "C")
  ELSEIF(${A_LANGUAGE} STREQUAL "CXX")
    SET(language "C++")
  ELSEIF(${A_LANGUAGE} STREQUAL "Fortran")
    SET(language "Fortran")
  ENDIF()

  SET(${A_VAR} "${name} ${language} ${version}" PARENT_SCOPE)

ENDFUNCTION(COMPILER_LABEL)

# ------------------------------------------------------------------------------
#
# CONFIGURATION_REPORT()
#
# Generate a report on the configuration for a Hermes build.
#
# Output a series of messages that summarize the configuration for the Hermes
# build.
#
# ------------------------------------------------------------------------------

FUNCTION(CONFIGURATION_REPORT)

  SET(bv "${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION}")
  YES_OR_NO(build_compiler ${BUILD_COMPILER})
  YES_OR_NO(build_cpp ${BUILD_CPP})
  YES_OR_NO(build_fortran ${BUILD_FORTRAN})
  YES_OR_NO(build_python ${BUILD_PYTHON})
  YES_OR_NO(build_docs ${BUILD_DOCS})
  YES_OR_NO(build_tests ${BUILD_TESTS})
  COMPILER_LABEL(VAR cxx_compiler LANGUAGE CXX)
  COMPILER_LABEL(VAR fortran_compiler LANGUAGE Fortran)
  VERSION_OR_NOT_FOUND(VAR python_interpreter PACKAGE Python FOUND PYTHONINTERP_FOUND VERSION PYTHON_VERSION_STRING)
  VERSION_OR_NOT_FOUND(VAR pip_version PACKAGE Pip)
  VERSION_OR_NOT_FOUND(VAR asciidoctor_version PACKAGE Asciidoctor)
  VERSION_OR_NOT_FOUND(VAR boost_version PACKAGE Boost VERSION bv)
  VERSION_OR_NOT_FOUND(VAR zmq_version PACKAGE ZeroMQ)

  MESSAGE(STATUS "")
  MESSAGE(STATUS "Configuration Summary")
  MESSAGE(STATUS "---------------------")
  MESSAGE(STATUS "")
  MESSAGE(STATUS "  Build compiler             : ${build_compiler}")
  MESSAGE(STATUS "  Build C++ library          : ${build_cpp}")
  MESSAGE(STATUS "  Build Fortran library      : ${build_fortran}")
  MESSAGE(STATUS "  Build Python library       : ${build_python}")
  MESSAGE(STATUS "  Build documentation        : ${build_docs}")
  MESSAGE(STATUS "  Build tests                : ${build_tests}")
  MESSAGE(STATUS "")
  IF(cxx_compiler)
    MESSAGE(STATUS "  C++ compiler               : ${cxx_compiler}")
  ENDIF()
  IF(fortran_compiler)
    MESSAGE(STATUS "  Fortran compiler           : ${fortran_compiler}")
  ENDIF()
  IF(BUILD_PYTHON)
    MESSAGE(STATUS "  Python interpreter         : ${python_interpreter}")
    MESSAGE(STATUS "  Pip installer              : ${pip_version}")
  ENDIF()
  IF(BUILD_DOCS)
    MESSAGE(STATUS "  Asciidoctor version        : ${asciidoctor_version}")
  ENDIF()
  IF(BUILD_COMPILER)
    MESSAGE(STATUS "  Boost version              : ${boost_version}")
  ENDIF()
  IF(BUILD_CPP OR BUILD_FORTRAN)
    MESSAGE(STATUS "  ZeroMQ version             : ${zmq_version}")
  ENDIF()
  MESSAGE(STATUS "")
  MESSAGE(STATUS "  Installation prefix        : ${CMAKE_INSTALL_PREFIX}")
  MESSAGE(STATUS "")

ENDFUNCTION(CONFIGURATION_REPORT)
