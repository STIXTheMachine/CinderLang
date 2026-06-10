cmake_minimum_required(VERSION 3.29)
project(CinderLang)

add_subdirectory(tools)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(
        GLOB_RECURSE
        SOURCE_FILES
        CONFIGURE_DEPENDS
        ${SRC_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

#add_custom_command(
#        TARGET ${PROJECT_NAME}
#        PRE_BUILD
#        COMMAND $<TARGET_FILE:CinderTokGen>
#)