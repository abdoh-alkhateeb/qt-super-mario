cmake_minimum_required(VERSION 3.10)
project(qt_super_mario)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

add_executable(myapp
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(myapp PRIVATE include)

target_link_libraries(myapp
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)
