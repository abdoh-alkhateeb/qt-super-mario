cmake_minimum_required(VERSION 3.21)
project(qt-super-mario-Ziad)
set(PROJECT_SOURCES
src/main.cpp
src/player.cpp
include/player.hpp)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED Widgets)
add_executable(SuperMarioZiad ${PROJECT_SOURCES})
target_link_libraries(SuperMarioZiad PRIVATE Qt6::Widgets)
target_include_directories(SuperMarioZiad PRIVATE include)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

