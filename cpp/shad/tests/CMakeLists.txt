add_headers_and_sources(shad ${CMAKE_CURRENT_SOURCE_DIR})

macro(add_test test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE shad_core gtest gtest_main)
    target_include_directories(${test_name} PRIVATE "${PROJECT_SOURCE_DIR}/src")
endmacro()

add_test(algo_test)
add_test(matr_test)
add_test(sphere_test)
