cmake_minimum_required(VERSION 2.6)
project(maze)

set(CMAKE_CXX_STANDARD 11)

# Hier werden alle Source-Files eingetragen
set(SOURCE_FILES
        src/ss17/algodat/maze/main.cpp
        src/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearch.cpp
        src/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearch.h
        test/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearchTest.cpp)

include(CTest)
add_subdirectory(src/ss17/algodat/maze)
add_subdirectory(test/ss17/algodat/maze)
add_subdirectory(gtest)
