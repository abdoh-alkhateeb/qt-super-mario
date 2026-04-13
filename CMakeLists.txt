cmake_minimum_required(VERSION 3.16)
project(qt-super-mario)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)

add_executable(myapp src/main.cpp src/player.cpp include/player.hpp)

target_link_libraries(myapp PRIVATE Qt6::Widgets)
target_include_directories(myapp PRIVATE include)
