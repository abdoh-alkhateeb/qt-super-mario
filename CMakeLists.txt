cmake_minimum_required(VERSION 3.21)

project(Supermario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(Supermario src/main.cpp src/player.cpp include/player.hpp)

target_include_directories(Supermario PRIVATE include)

target_link_libraries(Supermario Qt6::Widgets)
