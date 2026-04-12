cmake_minimum_required(VERSION 3.14)
project(assignment2)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_executable(marioo
    src/main.cpp
    src/player.cpp
    include/player.hpp
)
target_include_directories(marioo PRIVATE include/)
target_link_libraries(marioo Qt6::Widgets)