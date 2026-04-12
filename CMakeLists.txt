cmake_minimum_required(VERSION 3.21)
project(mario)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

set(CMAKE_AUTOMOC ON)

add_executable(mariogame src/main.cpp src/player.cpp include/player.hpp)

target_link_libraries(mariogame PRIVATE Qt6::Widgets)
target_link_libraries(mariogame PRIVATE Qt6::Core)
target_link_libraries(mariogame PRIVATE Qt6::Gui)


target_include_directories(mariogame PRIVATE include)
