# CMakeList.txt : CMake project for Task10.1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Task10.1")

# Add source to this project's executable.
add_executable (Task10.1 "Task10.1.cpp" "Task10.1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task10.1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
