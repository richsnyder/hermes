# List all of the source files.

SET(DOC_SOURCES
  index.adoc
)

SET(DOC_INCLUDES
  ../INSTALL.adoc
  ../LICENSE.adoc
  ../README.adoc
  grammar.adoc
  hermes.adoc
  tutorial.adoc
)

SET(DOC_ASSETS
  assets/style.css
  assets/hermes.svg
)

# Copy assets to the build directory.

IF(NOT "${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  FOREACH(asset ${DOC_ASSETS})
    SET(src ${CMAKE_CURRENT_SOURCE_DIR}/${asset})
    SET(dst ${CMAKE_CURRENT_BINARY_DIR}/${asset})
    ADD_CUSTOM_COMMAND(
      OUTPUT ${dst}
      MAIN_DEPENDENCY ${src}
      COMMAND ${CMAKE_COMMAND}
      ARGS -E copy ${src} ${dst}
    )
    LIST(APPEND assets ${dst})
  ENDFOREACH()
ENDIF()

# Generate the HTML documentation.

FOREACH(src ${DOC_SOURCES})
  GET_FILENAME_COMPONENT(dir "${src}" DIRECTORY)
  GET_FILENAME_COMPONENT(name_we "${src}" NAME_WE)
  IF(dir)
    SET(dst "${CMAKE_CURRENT_BINARY_DIR}/${dir}/${name_we}.html")
  ELSE()
    SET(dst "${CMAKE_CURRENT_BINARY_DIR}/${name_we}.html")
  ENDIF()
  SET(attrs -a hermes-version=${PROJECT_VERSION})
  ADD_CUSTOM_COMMAND(
    OUTPUT ${dst}
    MAIN_DEPENDENCY ${src}
    DEPENDS ${DOC_INCLUDES}
    COMMAND ${Asciidoctor_EXECUTABLE}
    ARGS -b html5 -D ${CMAKE_CURRENT_BINARY_DIR} ${attrs} -o ${dst} ${src}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  )
  LIST(APPEND pages ${dst})
ENDFOREACH()

# Define the documentation target and mark files for installation.

ADD_CUSTOM_TARGET(doc ALL DEPENDS ${assets} ${pages})
INSTALL(FILES ${assets} DESTINATION doc/html/assets)
INSTALL(FILES ${pages} DESTINATION doc/html)
