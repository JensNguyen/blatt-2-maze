cmake_minimum_required(VERSION 3.7)

# Jeder weitere Test muss mit allen drei Befehlen eingebunden werden.
add_executable(BreathFirstSearchTest shortest_path/breadth_first_search/BreathFirstSearchTest.cpp)
target_link_libraries(BreathFirstSearchTest maze gtest gmock_main)
add_test(BreathFirstSearchTest BreathFirstSearchTest)
