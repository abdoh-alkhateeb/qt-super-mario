cmake_minimum_required(VERSION 3.21)
project(QtSuperMario)

set(CMAKE_AUTOMOC ON)   # Required for Q_OBJECT macro processing

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(QtSuperMario
    src/main.cpp
    src/player.cpp
    include/player.hpp   # Must be listed so MOC processes the Q_OBJECT macro
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_include_directories(QtSuperMario PRIVATE include)
target_link_libraries(QtSuperMario PRIVATE Qt6::Widgets)
