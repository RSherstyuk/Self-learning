# linked_list.h and linked_list.cpp form a library.
add_library(ten_linked_list_lib STATIC linked_list.cpp)
target_include_directories(ten_linked_list_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# list_node.h is a header-only component used by leet_code_list_test.
# No separate target is needed for it, its directory will be added to consuming targets.
