project(commons)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(COMMONS_SRC ${PROJECT_SOURCE_DIR}/base64.cpp include/base64.h)

add_library(commons STATIC ${COMMONS_SRC})

target_include_directories(commons PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)