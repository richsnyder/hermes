# List all of the source files.

SET(SOURCES
  fruit_util.f90
  fruit.f90
  driver.f90
)

# Define the test target.

ADD_EXECUTABLE(test-fortran ${SOURCES})
TARGET_LINK_LIBRARIES(test-fortran ${EXTRA_LIBS})

# Add the test.

ADD_TEST(NAME fortran COMMAND test-fortran)
