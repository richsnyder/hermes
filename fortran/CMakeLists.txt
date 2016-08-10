# Register all of the required dependencies.

INCLUDE_DIRECTORIES(${ZeroMQ_INCLUDE_DIRS})
LIST(APPEND EXTRA_LIBS ${ZeroMQ_LIBRARIES})

# Add the source code subdirectory.

ADD_SUBDIRECTORY(src)
