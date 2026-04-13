cmake_minimum_required(VERSION 3.16)
project(QtMario)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
include_directories(include)
add_executable(QtMario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_link_libraries(QtMario Qt6::Widgets)
