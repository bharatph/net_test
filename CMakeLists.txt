cmake_minimum_required (VERSION 2.8)
project (net_test)

find_package(Threads REQUIRED)

set (DEFAULT_PORT 5555)

#configure file to add CMake settings to it
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_SOURCE_DIR}/config.h"
	)


if( WIN32 ) #WINDOWS
    set( CMAKE_CXX_FLAGS "-Wno-write-strings -Wall -g -DDEBUG -std=gnu++11 -DWIN32 -mwindows")
else()     #LINUX
	set( CMAKE_CXX_FLAGS " -Wno-write-strings -lrt -Wall -ggdb3 -DDEBUG -std=c++11")
endif()

#include_directories ("${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE(client_test client_test.c)
ADD_EXECUTABLE(server_test server_test.c)


TARGET_LINK_LIBRARIES(client_test ${CMAKE_THREAD_LIBS_INIT} -ldl)
TARGET_LINK_LIBRARIES(server_test ${CMAKE_THREAD_LIBS_INIT} -ldl)
