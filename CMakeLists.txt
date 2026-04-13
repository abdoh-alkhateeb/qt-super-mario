cmake_minimum_required(VERSION 3.16)

project(QtSuperMario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtSuperMario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(QtSuperMario PRIVATE include)
target_link_libraries(QtSuperMario PRIVATE Qt6::Widgets)

