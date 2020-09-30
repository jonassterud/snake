cmake_minimum_required(VERSION 3.0.0)
project(snake VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(CTest)
enable_testing()

set(SOURCES
    src/Display.cpp
    src/Player.cpp
    src/main.cpp
)

add_executable(snake ${SOURCES})

target_include_directories(snake
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

set(CMAKE_CXX_FLAGS "-lncurses")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
