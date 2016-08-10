# List all of the source files.

SET(SOURCES driver.cpp)

# Register all of the required dependencies.

LIST(APPEND EXTRA_LIBS gtest)

# Define the test target.

SET(COMPILER_FEATURES cxx_auto_type)
ADD_EXECUTABLE(test-compiler ${SOURCES})
TARGET_COMPILE_FEATURES(test-compiler PUBLIC ${COMPILER_FEATURES})
TARGET_LINK_LIBRARIES(test-compiler ${EXTRA_LIBS})

# Add the test.

ADD_TEST(NAME compiler COMMAND test-compiler)
