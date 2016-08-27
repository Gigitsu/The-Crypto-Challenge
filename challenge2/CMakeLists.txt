project(challenge2)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_HEX_FIRST_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/first)
set(PROJECT_HEX_SECOND_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/second)
set(PROJECT_EXPECTED_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/expected)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

add_executable(challenge2 ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(challenge2 commons)