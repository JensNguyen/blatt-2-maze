cmake_minimum_required(VERSION 3.7)

# Jede weitere Source-File muss zur maze-Bibliothek hinzugefügt werden, um aus
# Tests sowie der main erreichbar zu sein!
add_library(maze shortest_path/breadth_first_search/BreathFirstSearch.cpp)

add_executable(main main.cpp tremaux/Tremaux.cpp tremaux/Tremaux.h)
target_link_libraries(main maze)
