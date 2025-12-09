# add_headers_and_sources(shad ${CMAKE_CURRENT_SOURCE_DIR}) # Not used, removing

# Define test executables with their specific dependencies
add_executable(date_test date_test.cpp)
target_link_libraries(date_test PRIVATE ten_date gtest gtest_main)

add_executable(two_test two_test.cpp)
target_link_libraries(two_test PRIVATE ten_two_pointers gtest gtest_main)

add_executable(leet_code_list_test leet_code_list_test.cpp)
target_link_libraries(leet_code_list_test PRIVATE gtest gtest_main)
target_include_directories(leet_code_list_test PRIVATE "${PROJECT_SOURCE_DIR}/linked_list") # For list_node.h

add_executable(linked_list_test linked_list_test.cpp)
target_link_libraries(linked_list_test PRIVATE ten_linked_list_lib gtest gtest_main)

add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test PRIVATE src_ten gtest gtest_main)

add_executable(sliding_window_test sliding_window_test.cpp)
target_link_libraries(sliding_window_test PRIVATE ten_sliding_window gtest gtest_main)
