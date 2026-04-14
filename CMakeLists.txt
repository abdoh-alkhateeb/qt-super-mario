cmake_minimum_required(VERSION 3.16)

project(QtMarioGame)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(QtMarioGame
    main.cpp
    player.cpp
    player.hpp
)

target_link_libraries(QtMarioGame Qt5::Widgets)