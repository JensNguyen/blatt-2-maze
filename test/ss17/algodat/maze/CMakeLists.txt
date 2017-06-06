cmake_minimum_required(VERSION 3.2)

# Jeder weitere Test muss mit allen drei Befehlen eingebunden werden.
add_executable(BreadthFirstSearchTest
        shortest_path/breadth_first_search/BreathFirstSearchLibTest.cpp
        shortest_path/breadth_first_search/PositionTest.cpp)
target_link_libraries(BreadthFirstSearchTest
        BreathFirstSearchLibrary
        gtest gmock_main)
add_test(BreadthFirstSearchTest BreadthFirstSearchTest)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()