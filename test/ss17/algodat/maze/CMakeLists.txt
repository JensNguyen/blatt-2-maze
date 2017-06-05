cmake_minimum_required(VERSION 3.2)

# Jeder weitere Test muss mit allen drei Befehlen eingebunden werden.
add_executable(BreathFirstSearchLibTest shortest_path/breadth_first_search/BreathFirstSearchLibTest.cpp)
target_link_libraries(BreathFirstSearchLibTest BreathFirstSearchLibrary gtest gmock_main)
add_test(BreathFirstSearchLibTest BreathFirstSearchLibTest)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()