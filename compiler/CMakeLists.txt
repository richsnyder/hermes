# Register all of the required dependencies.

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LIST(APPEND EXTRA_LIBS ${Boost_LIBRARIES})

# Add the source code subdirectory.

ADD_SUBDIRECTORY(src)
