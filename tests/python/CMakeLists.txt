# Add the test.

ADD_TEST(
    NAME python
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/driver.py
  )
