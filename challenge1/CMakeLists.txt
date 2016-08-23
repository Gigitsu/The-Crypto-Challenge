project(challenge1)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_HEX_FILE ${CMAKE_CURRENT_SOURCE_DIR}/resources/hex)

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

add_executable(challenge1 ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(challenge1 commons)