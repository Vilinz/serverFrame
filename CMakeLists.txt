cmake_minimum_required(VERSION 3.0)

project(vilin)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

include_directories(.)

set(LIB_SRC
	vilin/log/log.cc
	vilin/util.cc
	)

add_library(vilin SHARED ${LIB_SRC})

add_executable(test tests/test.cc)
add_dependencies(test vilin)
target_link_libraries(test vilin)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)







#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DDIR}cmake)
#include(cmake/utils.cmake)

#set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
#set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

#include_directories(.)
#include_directories(/apps/vilin/include)

#link_directories(/apps/vilin/lib)
#link_directories(/apps/vilin/lib64)

#option(BUILD_TEST "ON for compile test" OFF)

#set(LIB_SRC
#	vilin/testClass.cpp
#	)

#add_library(vilin SHARED ${LIB_SRC})
# force_redefine_file_macro_for_source(vilin)

#find_library(PTHREAD pthread)

#set(LIBS
#	vilin
#	pthread
#	)

#ilin_add_executable(test "tests/main.cpp" vilin "${LIBS}")

#SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)