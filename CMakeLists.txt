cmake_minimum_required(VERSION 3.10)
project(qt-super-mario)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(qt-super-mario src/main.cpp src/player.cpp include/player.hpp)

target_link_libraries(qt-super-mario PRIVATE Qt6::Core Qt6::Widgets)
target_include_directories(qt-super-mario PRIVATE include)

