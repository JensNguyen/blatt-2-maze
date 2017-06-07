cmake_minimum_required(VERSION 3.2)

#include all direcotries
include_directories(control)
include_directories(model)
include_directories(view)
include_directories(control)
include_directories(control/recursive_solver)

set(Qt5Widgets_DIR /opt/qt55/lib/cmake/Qt5Widgets)
set(Qt5Core_DIR /opt/qt55/lib/cmake/Qt5Core)

#active automoc
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#Find QT-Packeges
find_package(Qt5Widgets)
find_package(Qt5Core)


set(SOURCES
        main.cpp
        model/maze.cpp
        control/mazealgorithm.cpp
        control/mazegenerator.cpp
        view/mazegui.cpp
        control/recursive_solver/recursivemazesolvealgorithm.cpp
        control/shortest_path/breadth_first_search/BreadthFirstSearchGuiInteraction.cpp
        control/shortest_path/breadth_first_search/BreadthFirstSearch.cpp
        control/shortest_path/breadth_first_search/Position.cpp
        )

set(HEADERS
        model/maze.h
        control/mazealgorithm.h
        control/mazegenerator.h
        view/mazegui.h
        control/recursive_solver/recursivemazesolvealgorithm.h
        control/shortest_path/breadth_first_search/BreadthFirstSearchGuiInteraction.h
        control/shortest_path/breadth_first_search/BreadthFirstSearch.h
        control/shortest_path/breadth_first_search/Position.h
        )

set(UI
        view/mazegui.ui
        )

set(INCLUDE_DIRS
    control
    control/recursive_solver
    model
    view)


QT5_WRAP_UI(UI_HEADERS ${UI})

add_library(maze_solver ${SOURCES} ${HEADERS} ${UI_HEADERS})
add_executable(mazesolver main.cpp)

#Link qt libraries
TARGET_LINK_LIBRARIES(maze_solver PUBLIC Qt5::Widgets Qt5::Core)
TARGET_LINK_LIBRARIES (mazesolver PUBLIC maze_solver)

