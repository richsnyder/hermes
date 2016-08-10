# List all of the source files.

SET(FORTRAN_SOURCES
  xdr_utils.c
)

SET(FORTRAN_CONFIG_SOURCES
  zmq_constants.c
)

SET(FORTRAN_MODULES
  hermes
  uint
  xdr
  zmq
)

# Process the modules.

FOREACH(module ${FORTRAN_MODULES})
  SET(src ${CMAKE_CURRENT_SOURCE_DIR}/${module}.f90)
  SET(dst ${CMAKE_CURRENT_BINARY_DIR}/${module}.mod)
  LIST(APPEND FORTRAN_SOURCES ${src})
  INSTALL(FILES ${dst} DESTINATION include)
ENDFOREACH()

# Process the header files.

FOREACH(file ${FORTRAN_CONFIG_SOURCES})
  GET_FILENAME_COMPONENT(subdirectory ${file} DIRECTORY)
  SET(src ${CMAKE_CURRENT_SOURCE_DIR}/${file}.in)
  SET(dst ${CMAKE_CURRENT_BINARY_DIR}/${file})
  CONFIGURE_FILE(${src} ${dst})
  SET_SOURCE_FILES_PROPERTIES(${dst} GENERATED)
  LIST(APPEND FORTRAN_SOURCES ${dst})
ENDFOREACH(file)

# Define the library target.

ADD_LIBRARY(hermes-fortran STATIC ${FORTRAN_SOURCES})
TARGET_LINK_LIBRARIES(hermes-fortran ${EXTRA_LIBS})
SET_TARGET_PROPERTIES(hermes-fortran PROPERTIES OUTPUT_NAME hermes_fortran)
INSTALL(TARGETS hermes-fortran ARCHIVE DESTINATION lib)
