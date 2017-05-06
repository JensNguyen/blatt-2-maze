cmake_minimum_required(VERSION 2.8)
project(maze)

set(CMAKE_CXX_STANDARD 11)

# Hier werden alle Source-Files eingetragen
set(SOURCE_FILES
        src/ss17/algodat/maze/main.cpp
        src/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearch.cpp
        src/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearch.h
        test/ss17/algodat/maze/shortest_path/breadth_first_search/BreathFirstSearchTest.cpp)

include(CTest)
add_subdirectory(src/ss17/algodat/maze)
add_subdirectory(test/ss17/algodat/maze)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()