cmake_minimum_required(VERSION 3.2)

# Jede weitere Source-File muss zur maze-Bibliothek hinzugefügt werden, um aus
# Tests sowie der main erreichbar zu sein!
add_library(BreathFirstSearchLibrary
        shortest_path/breadth_first_search/BreadthFirstSearch.cpp
        shortest_path/breadth_first_search/BreadthFirstSearchLib.cpp
        shortest_path/breadth_first_search/Position.cpp
        )

add_executable(breadth_first_search_main breadth_first_search_main.cpp)
target_link_libraries(breadth_first_search_main BreathFirstSearchLibrary)
