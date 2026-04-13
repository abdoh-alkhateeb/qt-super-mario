cmake_minimum_required(VERSION 3.16)

project(game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(game src/main.cpp src/player.cpp include/player.hpp)

target_include_directories(game PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(game Qt6::Widgets)
