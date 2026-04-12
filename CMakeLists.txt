cmake_minimum_required(VERSION 3.16)
project(QtSuperMario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt MOC
set(CMAKE_AUTOMOC ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Executable
add_executable(mario
    src/main.cpp
    src/player.cpp
    include/player.hpp
)

# Include folder
target_include_directories(mario PRIVATE include)

# Link Qt
target_link_libraries(mario Qt6::Core Qt6::Widgets)