cmake_minimum_required(VERSION 3.16)

project(QtSuperMario VERSION 1.0 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)

include_directories(include)

add_executable(QtSuperMario 
    src/main.cpp
    src/player.cpp
    include/player.hpp)

target_link_libraries(QtSuperMario PRIVATE Qt6::Widgets)

