cmake_minimum_required(VERSION 3.23)

set(project "TheSandboxLite")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        ${CMAKE_SOURCE_DIR}/source/main.cpp
        ${CMAKE_SOURCE_DIR}/source/Scene.cpp
        ${CMAKE_SOURCE_DIR}/source/Cell.cpp)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

set(${project}_SOURCE_LIST ${${project}_SOURCES})

add_executable(${project} ${${project}_SOURCE_LIST})

target_link_libraries(${project} sfml-graphics)
target_link_libraries(${project} sfml-window)
target_link_libraries(${project} sfml-system)
