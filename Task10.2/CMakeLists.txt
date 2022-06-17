cmake_minimum_required (VERSION 3.8)

project ("Task10.2")

file(GLOB SOURCES
    *.h
    *.cpp
)

add_executable(Task10.2 ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task10.2 PROPERTY CXX_STANDARD 20)
endif()