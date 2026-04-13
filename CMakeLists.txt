cmake_minimum_required(VERSION 3.16)

project(qt-super-mario LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qt-super-mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(qt-super-mario PRIVATE include)

target_link_libraries(qt-super-mario PRIVATE Qt6::Widgets)
