cmake_minimum_required(VERSION 3.2)

add_library(BreathFirstSearchLibrary
        shortest_path/breadth_first_search/BreadthFirstSearch.cpp
       shortest_path/breadth_first_search/Position.cpp
       ../model/maze.cpp
       )