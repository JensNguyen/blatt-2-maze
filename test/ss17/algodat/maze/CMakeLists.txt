cmake_minimum_required(VERSION 2.6)

# Jeder weitere Test muss in add_executable hinzugefügt werden
add_executable(allTests shortest_path/breadth_first_search/BreathFirstSearchTest.cpp)
target_link_libraries(allTests maze gtest gtest_main)
add_test(allTests allTests)
