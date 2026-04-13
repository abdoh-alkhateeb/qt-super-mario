cmake_minimum_required(VERSION 3.10)
project(mariogame)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)

add_executable(my_app src/main.cpp src/player.cpp include/player.hpp)
target_include_directories(my_app PRIVATE include src)
target_link_libraries(my_app PRIVATE Qt6::Core Qt6::Widgets)
