cmake_minimum_required (VERSION 3.8)
project ("Task10.1")
add_executable (Task10.1 "Task10.1.cpp" "Task10.1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task10.1 PROPERTY CXX_STANDARD 20)
endif()