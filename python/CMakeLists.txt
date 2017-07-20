# List all of the source files.

SET(PYTHON_SOURCES
    hermes/__init__.py
    hermes/client.py
    hermes/error.py
    hermes/header.py
    hermes/server.py
)

# Configure the setup script.

CONFIGURE_FILE(setup.py.in setup.py)

# Define the Python package target.

SET(setup ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
SET(timestamp ${CMAKE_CURRENT_BINARY_DIR}/timestamp)
SET(timestamp_command ${CMAKE_COMMAND} -E touch ${timestamp})
SET(cleanup_command ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_SOURCE_DIR}/hermes.egg-info)

IF(Pip_FOUND)
  SET(wheel ${CMAKE_CURRENT_BINARY_DIR}/dist/hermes-${PROJECT_VERSION}-py2.py3-none-any.whl)
  SET(build_command ${PYTHON_EXECUTABLE} ${setup} bdist_wheel --universal)
  SET(install_command ${Pip_EXECUTABLE} install ${Pip_INSTALL_OPTIONS} ${wheel})
ELSE()
  SET(build_command ${PYTHON_EXECUTABLE} ${setup} build)
  SET(install_command ${PYTHON_EXECUTABLE} ${setup} ${Pip_INSTALL_OPTIONS} install)
ENDIF()

ADD_CUSTOM_COMMAND(
    OUTPUT ${timestamp}
    COMMAND ${build_command}
    COMMAND ${timestamp_command}
    COMMAND ${cleanup_command}
    DEPENDS ${PYTHON_SOURCES}
)
ADD_CUSTOM_TARGET(hermes-python ALL DEPENDS ${timestamp})
INSTALL(CODE "EXECUTE_PROCESS(COMMAND ${install_command})")
