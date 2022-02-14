cmake_minimum_required(VERSION 3.20)

# Project name and programming language
project(PipeNetwork)

# Gather files and store paths in CMake variables
file(GLOB PIPNET_HEADER_FILES pipenetwork/inc/*.h*)
file(GLOB PIPNET_LIBRARY_SOURCE_FILES pipenetwork/src/*.cpp)
file(GLOB PIPNET_TEST_SOURCE_FILES pipenetwork/test/*.cpp)
file(GLOB LINALG_HEADER_FILES linalg/inc/*.h*)
file(GLOB LINALG_TEST_SOURCE_FILES linalg/test/*.cpp)
file(GLOB LINALG_LIBRARY_SOURCE_FILES linalg/src/*.cpp)
file(GLOB DRIVERS_SOURCE_FILES drivers/*.cpp)

# Specify the folders with header files, otherwise our includes are not found
include_directories(pipenetwork/inc)
include_directories(linalg/inc)
include_directories(external/catch)

# Enables exporting all symbols to the dll on windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# When compiling with gcc we need to compile libraries with fPIC (stands for position independent code).
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -pedantic -Wall -Werror -std=c++17")
endif (CMAKE_COMPILER_IS_GNUCXX)

# Add compilation target for our library
add_library(linalg SHARED ${LINALG_LIBRARY_SOURCE_FILES} ${LINALG_HEADER_FILES})
add_library(pipenetwork SHARED ${PIPNET_LIBRARY_SOURCE_FILES} ${PIPNET_HEADER_FILES} ${LINALG_LIBRARY_SOURCE_FILES} ${LINALG_HEADER_FILES})

# Create executables for running the tests
add_executable(linalg_testrunner ${LINALG_TEST_SOURCE_FILES})
target_link_libraries(linalg_testrunner linalg)

add_executable(pipenetwork_testrunner ${PIPNET_TEST_SOURCE_FILES})
target_link_libraries(pipenetwork_testrunner pipenetwork)

# Create executables for running the main program
add_executable(driver ${DRIVERS_SOURCE_FILES} ${PIPNET_HEADER_FILES})
target_link_libraries(driver pipenetwork linalg)