cmake_minimum_required(VERSION 3.16)

project(MyQtProject)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MyQtProject
    src/main.cpp
    src/player.cpp
    include/player.hpp   
)


target_link_libraries(MyQtProject PRIVATE  Qt6::Widgets)
target_include_directories(MyQtProject PRIVATE include)
