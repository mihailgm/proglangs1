project(qt-cmake-project)
cmake_minimum_required(VERSION 3.0)
find_package(Qt5 COMPONENTS Core Widgets)

find_package(PythonLibs 3.4)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PYTHON_INCLUDE_DIRS})

add_definitions("-g")
set (CMAKE_CXX_STANDARD 11)

add_executable(hw1.1 test1.c widgets.h)
add_executable(hw1.2 test2.c widgets.h)

add_library(hw1lib SHARED hw1.cpp widgets.h)
target_link_libraries(hw1lib
    ${Qt5Core_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)


target_link_libraries(hw1.1 hw1lib)
target_link_libraries(hw1.2 hw1lib)

python_add_module(
    _pywidgets
    hw1py.cpp
)

target_link_libraries(_pywidgets
    hw1lib
)
