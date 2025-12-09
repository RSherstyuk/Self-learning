add_headers_and_sources(two ${CMAKE_CURRENT_SOURCE_DIR})
add_library(two ${two_headers} ${two_sources})
add_library(ten_two_pointers STATIC SolutionTwoPointers.cpp SolutionTwoPointersB.cpp)
target_include_directories(ten_two_pointers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
