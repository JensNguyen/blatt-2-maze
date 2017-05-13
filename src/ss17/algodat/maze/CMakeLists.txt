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

set(Qt5Widgets_DIR $ENV{HOME}/Qt/5.5/clang_64/lib/cmake/Qt5Widgets)
set(Qt5Core_DIR $ENV{HOME}/Qt/5.5/clang_64/lib/cmake/Qt5Core)

#Find QT-Packeges
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Core REQUIRED)

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

QT5_WRAP_UI(UI_HEADERS ${UI})

add_library(mazesolver ${SOURCES} ${HEADERS} ${UI_HEADERS})


#Link qt libraries
TARGET_INCLUDE_DIRECTORIES (mazesolver PUBLIC view)
TARGET_LINK_LIBRARIES(mazesolver PUBLIC Qt5::Widgets)
TARGET_LINK_LIBRARIES(mazesolver PUBLIC Qt5::Core)
