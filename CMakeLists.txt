cmake_minimum_required(VERSION 3.21)
project(calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(calculator src/main.cpp include/common.h include/FlowLayout.h include/Tool.h include/Window.h)

add_definitions(-DUNICODE)

target_link_libraries(calculator Comctl32.lib)