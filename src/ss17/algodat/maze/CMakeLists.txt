cmake_minimum_required(VERSION 3.2)

add_library(BreathFirstSearchLibrary
        shortest_path/breadth_first_search/BreathFirstSearchLib.cpp
        shortest_path/breadth_first_search/Position.cpp)

add_executable(maze
        main.cpp
        shortest_path/breadth_first_search/BreathFirstSearch.cpp)
target_link_libraries(maze BreathFirstSearchLibrary)
