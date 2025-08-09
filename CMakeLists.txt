cmake_minimum_required(VERSION 3.10)

project(
    kdemangle
    VERSION 0.0.0
    DESCRIPTION "Header-only C++11 library for demangling"
    HOMEPAGE_URL "https://github.com/KonstantIMP/kdemangle"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ./include/)

add_subdirectory(./tests/)
