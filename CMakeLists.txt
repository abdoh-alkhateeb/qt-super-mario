cmake_minimum_required(VERSION 3.21)
project(Mario)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_executable(mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(mario PRIVATE include)
target_link_libraries(mario Qt6::Core Qt6::Widgets)
