cmake_minimum_required(VERSION 3.16)
project(rasterizer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options
option(BUILD_TESTS "Build tests" OFF) # Set to ON to build tests

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Main executable
add_executable(rasterizer ${SRC_FILES})

# Tests (optionnel avec Catch2)
# if(BUILD_TESTS)
#     enable_testing()
#     add_executable(runTests tests/test_math.cpp)
#     add_test(NAME AllTests COMMAND runTests)
# endif()
