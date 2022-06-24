cmake_minimum_required (VERSION 3.8)

project ("FigureHierarchyDynamicLib")

file(GLOB SOURCES
    *.h
    *.cpp
)

add_library(FigureHierarchyDynamicLib SHARED ${SOURCES})
target_include_directories(FigureHierarchyDynamicLib PUBLIC ../FigureHierarchyDynamicLib)