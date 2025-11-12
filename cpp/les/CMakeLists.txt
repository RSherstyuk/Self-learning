cmake_minimum_required(VERSION 3.10)

project(les LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(core SHARED
   src/Raii.cpp 
)

add_library(graph SHARED
    graph/Graph.h
    graph/Graph.cpp
)

target_include_directories(core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(les
    src/main.cpp
)

target_link_libraries(les PRIVATE core graph)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(les_test
    tests/test.cpp
)

target_link_libraries(les_test PRIVATE 
    gtest_main 
    core
)

target_include_directories(les_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()

add_test(NAME run_all_tests COMMAND les_test)
