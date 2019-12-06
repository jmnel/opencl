# -- OpenCL Examples  --
# -- I am writing these as I learn OpenCL. They
# -- Serve as my personal notes.

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
add_definitions("+std=c++")

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()
find_library(OpenCL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_BUILD_TYPE Debug)
project(jmnel-opencl VERSION 0.1 LANGUAGES CXX)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

set( WARNING_FLAGS
    "-pedantic "
    "-Wall "
    "-Werror=return-type "
    "-Wextra "
    "-Wmissing-field-initializers "
    "-Wno-predefined-identifier-outside-function "
#    "-Wno-missing-braces "
    )

set( MISC_FLAGS
    "-Wpedantic "
    "-fcolor-diagnostics "
    "-fsanitize=undefined,address "
    "-mlzcnt "
#    "-fsanitize-trap=all "
#    "-fno-exceptions "
#    "-O2 -fprofile-instr-generate -fcoverage-mapping -fprofile-arcs -ftest-coverage "
#    "-O2 "
    )

string(CONCAT WARNING_FLAGS_STR ${WARNING_FLAGS})
string(CONCAT MISC_FLAGS_STR ${MISC_FLAGS})

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MISC_FLAGS_STR}${WARNING_FLAGS_STR}" )

#set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Arcturus_SOURCE_DIR}/../targets/Debug )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${jmnel-opencl_SOURCE_DIR}/targets/Debug )
set( CMAKE_MODULE_PATH ${jmnel_opencl_SOURCE_DIR}/cmake/modules )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_executable(jmnel-opcl main.cpp)
target_link_libraries(jmnel-opcl ${OpenCL_LIBRARY}
#target_link_libraries(jmnel-opcl ${CONAN_LIBS})
