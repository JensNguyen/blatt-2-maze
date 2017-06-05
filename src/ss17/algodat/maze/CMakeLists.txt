cmake_minimum_required(VERSION 3.2)

add_library(BreathFirstSearchLibrary
        control/shortest_path/breadth_first_search/BreathFirstSearchLib.cpp
        control/shortest_path/breadth_first_search/Position.cpp)

add_executable(maze
        breadth_first_search_main.cpp
        control/shortest_path/breadth_first_search/BreathFirstSearch.cpp)
target_link_libraries(maze BreathFirstSearchLibrary)