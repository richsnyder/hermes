# List all of the source files.

SET(COMPILER_SOURCES
  clp.cpp
  main.cpp
  state/alias.cpp
  state/basic.cpp
  state/blueprint.cpp
  state/constant.cpp
  state/container.cpp
  state/datatype.cpp
  state/enumeration.cpp
  state/exception.cpp
  state/field.cpp
  state/interface.cpp
  state/io.cpp
  state/procedure.cpp
  state/space.cpp
  state/structure.cpp
  parser/id.cpp
  generator/generate.cpp
  generator/iomanip.cpp
  generator/utilities.cpp
  generator/cpp/alias.cpp
  generator/cpp/basic.cpp
  generator/cpp/container.cpp
  generator/cpp/datatype.cpp
  generator/cpp/enumeration.cpp
  generator/cpp/exception.cpp
  generator/cpp/field.cpp
  generator/cpp/generator.cpp
  generator/cpp/structure.cpp
  generator/cpp/translate.cpp
  generator/fortran/alias.cpp
  generator/fortran/basic.cpp
  generator/fortran/container.cpp
  generator/fortran/datatype.cpp
  generator/fortran/enumeration.cpp
  generator/fortran/exception.cpp
  generator/fortran/field.cpp
  generator/fortran/generator.cpp
  generator/fortran/sizer.cpp
  generator/fortran/sizevar.cpp
  generator/fortran/structure.cpp
  generator/fortran/translate.cpp
  generator/python/alias.cpp
  generator/python/basic.cpp
  generator/python/container.cpp
  generator/python/datatype.cpp
  generator/python/enumeration.cpp
  generator/python/exception.cpp
  generator/python/field.cpp
  generator/python/generator.cpp
  generator/python/structure.cpp
  generator/python/translate.cpp
)

SET(COMPILER_CONFIG_HEADERS
  version.hpp
  tclap/config.h
)

# Include the necessary CMake modules.

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckIncludeFileCXX)
INCLUDE(CheckTypeSize)

# Create the TCLAP configuration file.

CHECK_INCLUDE_FILES(float.h HAVE_FLOAT_H)
CHECK_INCLUDE_FILES(inttypes.h HAVE_INTTYPES_H)
CHECK_INCLUDE_FILES(memory.h HAVE_MEMORY_H)
CHECK_INCLUDE_FILES(stdarg.h HAVE_STDARG_H)
CHECK_INCLUDE_FILES(stdint.h HAVE_STDINT_H)
CHECK_INCLUDE_FILES(stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES(string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES(strings.h HAVE_STRINGS_H)
CHECK_INCLUDE_FILES(unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILES(sys/stat.h HAVE_SYS_STAT_H)
CHECK_INCLUDE_FILES(sys/types.h HAVE_SYS_TYPES_H)
CHECK_INCLUDE_FILE_CXX(sstream HAVE_SSTREAM)
CHECK_INCLUDE_FILE_CXX(strstream HAVE_STRSTREAM)
CHECK_TYPE_SIZE("long long" SIZEOF_LONG_LONG)

SET(HAVE_NAMESPACES 1)
IF(HAVE_STRSTREAM)
  SET(HAVE_CLASS_STRSTREAM 1)
ENDIF()
IF(SIZEOF_LONG_LONG GREATER 0)
  SET(HAVE_LONG_LONG 1)
ENDIF()
IF(HAVE_FLOAT_H AND HAVE_STDARG_H AND HAVE_STDINT_H AND HAVE_STRING_H)
  SET(STDC_HEADERS 1)
ENDIF()

SET(src ${CMAKE_CURRENT_SOURCE_DIR}/tclap/config.h.in)
SET(dst ${CMAKE_CURRENT_BINARY_DIR}/tclap/config.h)
CONFIGURE_FILE(${src} ${dst})

# Identify the directories that contain include files.

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/include)

# Process the header files.

FOREACH(file ${COMPILER_CONFIG_HEADERS})
  SET(src ${CMAKE_CURRENT_SOURCE_DIR}/${file}.in)
  SET(dst ${CMAKE_CURRENT_BINARY_DIR}/include/${file})
  CONFIGURE_FILE(${src} ${dst})
ENDFOREACH(file)

# Define the executable target.

SET(COMPILER_FEATURES cxx_auto_type cxx_variadic_templates)
ADD_EXECUTABLE(hermes-compiler ${COMPILER_SOURCES})
TARGET_COMPILE_FEATURES(hermes-compiler PUBLIC ${COMPILER_FEATURES})
TARGET_LINK_LIBRARIES(hermes-compiler ${EXTRA_LIBS})
SET_TARGET_PROPERTIES(hermes-compiler PROPERTIES OUTPUT_NAME hermes)
INSTALL(TARGETS hermes-compiler RUNTIME DESTINATION bin)
