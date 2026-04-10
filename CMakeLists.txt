cmake_minimum_required(VERSION 3.16)
project(Homework2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(game_app
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(game_app PRIVATE include)

target_link_libraries(game_app PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
