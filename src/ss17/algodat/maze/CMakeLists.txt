cmake_minimum_required(VERSION 3.2)

add_library(BreathFirstSearchLibrary
        shortest_path/breadth_first_search/BreathFirstSearch.cpp)

add_executable(maze
        Main.cpp)

target_link_libraries(
        maze
        BreathFirstSearchLibrary)
