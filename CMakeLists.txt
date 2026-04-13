cmake_minimum_required(VERSION 3.16)
project(QtSuperMario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(include)

add_executable(QtSuperMario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

target_link_libraries(QtSuperMario Qt6::Widgets)
