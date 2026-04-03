cmake_minimum_required(VERSION 3.21)
project(Qt-Super-Mario)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(qtsm
        src/main.cpp
        src/player.cpp
        include/player.hpp
)

target_include_directories(qtsm PRIVATE include src)
target_link_libraries(qtsm PRIVATE Qt6::Widgets)