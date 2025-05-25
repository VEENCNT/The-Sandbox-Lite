cmake_minimum_required(VERSION 3.23)

set(project "Materials")
project(${project})

set(CMAKE_CXX_STANDARD 20)

set(${project}_SOURCES
        Stone.cpp
        Sand.cpp
        Water.cpp
        Wick.cpp
        Gunpowder.cpp
        Diesel.cpp
        Fire.cpp
        Lava.cpp
        Smoke.cpp
        None.cpp
)

add_library(${project} STATIC
    ${${project}_SOURCES}
)

target_include_directories(${project} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(Materials sfml-graphics sfml-window sfml-system)