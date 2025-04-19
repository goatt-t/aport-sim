cmake_minimum_required(VERSION 3.10)

project(AportSim VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
configure_file(
    include/AportSimConfig.h.in
    ${CMAKE_BINARY_DIR}/AportSimConfig.h
)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}          
)

add_executable(aport_sim
    src/main.cpp
    src/sim.cpp
)