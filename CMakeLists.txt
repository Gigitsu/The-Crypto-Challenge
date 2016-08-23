cmake_minimum_required(VERSION 3.6)
project(TheCryptoChallenge)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(commons)
add_subdirectory(challenge1)