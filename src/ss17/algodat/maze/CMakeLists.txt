cmake_minimum_required(VERSION 3.2)

#include all direcotries
include_directories(control)
include_directories(model)
include_directories(view)
include_directories(control)
include_directories(control/recursive_solver)


#active automoc
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#Find QT-Packeges
find_package(Qt4 4.8.6 REQUIRED QtWidgets Core QtGui)


set(SOURCES
        model/maze.cpp
        control/mazealgorithm.cpp
        control/mazegenerator.cpp
        view/mazegui.cpp
        control/recursive_solver/recursivemazesolvealgorithm.cpp
        )

set(HEADERS
        model/maze.h
        control/mazealgorithm.h
        control/mazegenerator.h
        view/mazegui.h
        control/recursive_solver/recursivemazesolvealgorithm.h
        )

set(UI
        view/mazegui.ui
        )

set(INCLUDE_DIRS
    control
    control/recursive_solver
    model
    view)


QT4_WRAP_UI(UI_HEADERS ${UI})

add_library(maze_solver ${SOURCES} ${HEADERS} ${UI_HEADERS})
add_executable(main main.cpp)


#Link qt libraries
TARGET_INCLUDE_DIRECTORIES (maze_solver PUBLIC ${INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(maze_solver PUBLIC Qt4::Widgets Qt4::QtCore Qt4::QtGui)