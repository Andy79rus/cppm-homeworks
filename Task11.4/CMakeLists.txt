# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Task11.4")

include_directories("FigureHierarchyDynamicLib/")

add_executable(FigureHierarchyConsole FigureHierarchyConsole.cpp)
add_subdirectory("FigureHierarchyDynamicLib")

target_link_libraries(FigureHierarchyConsole FigureHierarchyDynamicLib)