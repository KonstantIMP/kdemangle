cmake_minimum_required(VERSION 3.10)

project(
    kdemangle
    VERSION 0.0.0
    DESCRIPTION "And what"
    HOMEPAGE_URL ""
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ./include/)

add_subdirectory(./tests/)
