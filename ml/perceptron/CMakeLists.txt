cmake_minimum_required(VERSION 3.16)

project (precept LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_EXTENSIONS ON) # Same as gnu++2a (ON) vs c++2a (OFF): https://cmake.org/cmake/help/latest/prop_tgt/CXX_EXTENSIONS.html
set (CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/glob_sources.cmake)

add_subdirectory(contrlib)
add_subdirectory(src)
add_subdirectory(tests)

