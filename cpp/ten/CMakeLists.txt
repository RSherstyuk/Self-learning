cmake_minimum_required(VERSION 3.10)

project(ten LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(core STATIC
    src/SolutionTwoPointers.cpp
)

target_include_directories(core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(ten
    src/main.cpp
)

target_link_libraries(ten PRIVATE core)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(ten_test 
    tests/two_test.cpp
)

target_link_libraries(ten_test PRIVATE 
    gtest_main 
    core
)

target_include_directories(ten_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include

)

enable_testing()

add_test(NAME run_all_tests COMMAND ten_test)
