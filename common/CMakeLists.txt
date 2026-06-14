cmake_minimum_required(VERSION 3.29)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(
        GLOB_RECURSE
        SOURCE_FILES
        CONFIGURE_DEPENDS
        ${SRC_DIR}/*.cpp
)

add_library(CinderCommon STATIC ${SOURCE_FILES})
target_include_directories(CinderCommon PUBLIC ${INCLUDE_DIR})