cmake_minimum_required(VERSION 3.16)
project(GameProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON) 

add_executable(GameProject
    src/main.cpp
    src/player.cpp
    include/player.hpp
)
target_include_directories(GameProject PRIVATE include)
target_link_libraries(GameProject PRIVATE Qt6::Widgets)
