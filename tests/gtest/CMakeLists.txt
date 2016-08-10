# Define the library target.

ADD_LIBRARY(gtest STATIC gtest.cpp)
TARGET_LINK_LIBRARIES(gtest ${EXTRA_LIBS})
