# List all of the source files.

SET(CPP_SOURCES
  archive.cpp
  client.cpp
  error.cpp
  header.cpp
  memory.cpp
  server.cpp
)

SET(CPP_HEADERS
  hermes.hpp
  hermes/archive.hpp
  hermes/client.hpp
  hermes/error.hpp
  hermes/header.hpp
  hermes/memory.hpp
  hermes/server.hpp
)

SET(CPP_CONFIG_HEADERS)

# Identify the directories that contain include files.

INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/include)

# Process the header files.

FOREACH(file ${CPP_HEADERS})
  GET_FILENAME_COMPONENT(subdirectory ${file} DIRECTORY)
  INSTALL(FILES ${file} DESTINATION include/${subdirectory})
ENDFOREACH(file)
FOREACH(file ${CPP_CONFIG_HEADERS})
  GET_FILENAME_COMPONENT(subdirectory ${file} DIRECTORY)
  SET(src ${CMAKE_CURRENT_SOURCE_DIR}/${file}.in)
  SET(dst ${CMAKE_CURRENT_BINARY_DIR}/include/${file})
  CONFIGURE_FILE(${src} ${dst})
  INSTALL(FILES ${dst} DESTINATION include/${subdirectory})
ENDFOREACH(file)

# Define the library target.

SET(CPP_FEATURES cxx_auto_type)
ADD_LIBRARY(hermes-cpp SHARED ${CPP_SOURCES})
TARGET_COMPILE_FEATURES(hermes-cpp PUBLIC ${CPP_FEATURES})
TARGET_LINK_LIBRARIES(hermes-cpp ${EXTRA_LIBS})
SET_TARGET_PROPERTIES(hermes-cpp PROPERTIES OUTPUT_NAME hermes_cpp)
INSTALL(TARGETS hermes-cpp LIBRARY DESTINATION lib)
