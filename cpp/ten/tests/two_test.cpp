find_package(GTest CONFIG REQUIRED)

# Test for two_pointers
add_executable(two_pointers_test two_test.cpp)
target_link_libraries(two_pointers_test PRIVATE GTest::gtest_main ten_two_pointers ten_sliding_window ten_linked_list_lib ten_date)
target_include_directories(two_pointers_test PRIVATE
    ${CMAKE_SOURCE_DIR}/two_pointers
    ${CMAKE_SOURCE_DIR}/sliding_window
    ${CMAKE_SOURCE_DIR}/linked_list # For linked_list.h and list_node.h
    ${CMAKE_SOURCE_DIR}/src # For Date.h
    ${CMAKE_SOURCE_DIR}/lru # For lru.h
    ${CMAKE_SOURCE_DIR}/sq_dir # For stack.h, queue.h
)

# Test for matrix
add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test PRIVATE GTest::gtest_main)
target_include_directories(matrix_test PRIVATE
    ${CMAKE_SOURCE_DIR}/include # For Matrix.hpp
)

# Test for linked_list
add_executable(linked_list_test linked_list_test.cpp)
target_link_libraries(linked_list_test PRIVATE GTest::gtest_main ten_linked_list_lib)
target_include_directories(linked_list_test PRIVATE
    ${CMAKE_SOURCE_DIR}/linked_list # For linked_list.h
)

# Test for Date
add_executable(date_test date_test.cpp)
target_link_libraries(date_test PRIVATE GTest::gtest_main ten_date)
target_include_directories(date_test PRIVATE
    ${CMAKE_SOURCE_DIR}/src # For Date.h
)

# Test for sliding_window
add_executable(sliding_window_test sliding_window_test.cpp)
target_link_libraries(sliding_window_test PRIVATE GTest::gtest_main ten_sliding_window)
target_include_directories(sliding_window_test PRIVATE
    ${CMAKE_SOURCE_DIR}/sliding_window # For SlidingWindow.h
)

# Test for list_node (from linked_list directory)
add_executable(leet_code_list_test leet_code_list_test.cpp)
target_link_libraries(leet_code_list_test PRIVATE GTest::gtest_main)
target_include_directories(leet_code_list_test PRIVATE
    ${CMAKE_SOURCE_DIR}/linked_list # For list_node.h
)

