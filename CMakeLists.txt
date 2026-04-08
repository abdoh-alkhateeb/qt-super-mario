cmake_minimum_required(VERSION 3.10)
project(Mario_qt)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_library(Player src/player.cpp include/player.hpp)
target_include_directories(Player PUBLIC include)
target_link_libraries(Player PUBLIC Qt6::Widgets)

add_executable(Mario src/main.cpp)
target_sources(Mario PRIVATE include/player.hpp)
target_link_libraries(Mario PRIVATE Player)