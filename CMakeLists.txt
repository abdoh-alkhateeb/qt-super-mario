cmake_minimum_required(VERSION 3.21)
project(qt-super-mario2)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qt-super-mario2
    ../src/main.cpp
    ../src/player.cpp
    ../include/player.hpp
)

target_include_directories(qt-super-mario2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(qt-super-mario2 PRIVATE Qt6::Widgets)
