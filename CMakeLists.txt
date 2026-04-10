cmake_minimum_required(VERSION 3.21)
project(my)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)

add_executable(my src/main.cpp src/player.cpp include/player.hpp)
target_include_directories(my PRIVATE include src)
target_link_libraries(my PRIVATE Qt6::Widgets)
