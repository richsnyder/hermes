# List all of the source files.

SET(SOURCES driver.cpp)

# Register all of the required dependencies.

LIST(APPEND EXTRA_LIBS gtest)

# Define the test target.

SET(COMPILER_FEATURES cxx_auto_type)
ADD_EXECUTABLE(test-cpp ${SOURCES})
TARGET_COMPILE_FEATURES(test-cpp PUBLIC ${COMPILER_FEATURES})
TARGET_LINK_LIBRARIES(test-cpp ${EXTRA_LIBS})

# Add the test.

ADD_TEST(NAME cpp COMMAND test-cpp)
