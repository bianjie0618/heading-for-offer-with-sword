cmake_minimum_required(VERSION 3.10)

project(DataStructure)

set(CMake_BUILD_TYPE "Debug")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(Target ${PROJECT_SOURCE_DIR}/src/leetcode/49.cpp)

add_executable(main ${Target})