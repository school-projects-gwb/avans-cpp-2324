cmake_minimum_required(VERSION 3.26)
project(assessment_cplus_23_24_gunwunbun)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/game)

file(GLOB_RECURSE SOURCES src/*.cc src/*.h)
add_executable(assessment_cplus_23_24_gunwunbun ${SOURCES}
        src/game/spaceship/cargo.cc
        src/game/spaceship/cargo.h)