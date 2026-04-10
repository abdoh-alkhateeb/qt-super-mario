cmake_minimum_required(VERSION 3.21)
project(qtsupermario)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(game
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(game PRIVATE include)

target_link_libraries(game Qt5::Widgets)
