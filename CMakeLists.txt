cmake_minimum_required(VERSION 3.16)

project(mario)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_add_executable(mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(mario PRIVATE include)

target_link_libraries(mario
    PRIVATE
    Qt6::Core
    Qt6::Widgets
)
