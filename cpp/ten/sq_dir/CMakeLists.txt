# stack.cpp and queue.cpp (even if empty) form a library.
add_library(ten_stack_queue STATIC stack.cpp queue.cpp)
target_include_directories(ten_stack_queue PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
