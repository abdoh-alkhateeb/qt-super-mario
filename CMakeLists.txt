cmake_minimum_required(VERSION 3.10)
project(mygame)

set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} main.cpp player.cpp player.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
