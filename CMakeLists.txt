cmake_minimum_required(VERSION 3.16)
project(SuperMario)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_add_executable(SuperMario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_include_directories(SuperMario PRIVATE include)

target_link_libraries(SuperMario PRIVATE Qt6::Core Qt6::Widgets)
