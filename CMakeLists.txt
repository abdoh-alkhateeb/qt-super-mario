cmake_minimum_required(VERSION 3.21)
project(myapp)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(myapp src/main.cpp src/player.cpp include/player.hpp)

target_include_directories(myapp PRIVATE include)

target_link_libraries(myapp PRIVATE Qt6::Widgets)
