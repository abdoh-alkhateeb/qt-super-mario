cmake_minimum_required(VERSION 3.10)
project(mario)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(mario_app main.cpp player.cpp player.hpp)

target_link_libraries(mario_app PRIVATE Qt6::Widgets)
