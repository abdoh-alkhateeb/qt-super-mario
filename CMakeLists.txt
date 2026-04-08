cmake_minimum_required(VERSION 3.21)
set(CMAKE_AUTOMOC ON)

project(supermario)
add_executable(game src/main.cpp src/player.cpp include/player.hpp)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(game PRIVATE Qt6::Widgets)
target_include_directories(game PRIVATE include)
