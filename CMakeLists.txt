cmake_minimum_required(VERSION 3.16)

project(qt-super-mario LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(qt-super-mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(qt-super-mario PRIVATE include)

target_link_libraries(qt-super-mario PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
