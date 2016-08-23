cmake_minimum_required(VERSION 3.6)
project(challenge1)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_HEX_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/hex)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_executable(challenge1 ${PROJECT_SOURCE_DIR}/main.cpp)