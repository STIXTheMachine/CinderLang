cmake_minimum_required(VERSION 3.29)
project(CinderLang)

add_subdirectory(tools)
add_subdirectory(common)

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


set(GENERATED_TOKENS ${CMAKE_CURRENT_BINARY_DIR}/generated/Token.generated.hpp)
add_custom_command(
        OUTPUT ${GENERATED_TOKENS}
        COMMAND tools/Kindling/Kindling.exe ../spec/tokens.def ./generated/Token.generated.hpp
        DEPENDS tools/Kindling/Kindling.exe ../spec/tokens.def
        VERBATIM
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_sources(${PROJECT_NAME} PRIVATE ${GENERATED_TOKENS})
target_link_libraries(${PROJECT_NAME} PRIVATE CinderCommon)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR}/generated)
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE stdc++exp)
endif()