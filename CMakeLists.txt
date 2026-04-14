cmake_minimum_required(VERSION 3.16)

project(qt-super-mario)

set(CMAKE_CXX_STANDARD 17)

# Required for Qt signals/slots (Q_OBJECT)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(qt-super-mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

# So the compiler can find headers inside /include
target_include_directories(qt-super-mario PRIVATE include)

target_link_libraries(qt-super-mario Qt6::Core Qt6::Widgets)
