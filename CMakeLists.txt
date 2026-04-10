cmake_minimum_required(VERSION 3.12)
project(MarioGame)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(player STATIC src/player.cpp include/player.hpp)

add_executable(myapp src/main.cpp src/player.cpp include/player.hpp)

target_include_directories(player PRIVATE include)
target_link_libraries(myapp PRIVATE player)
target_link_libraries(player PUBLIC Qt6::Widgets)
