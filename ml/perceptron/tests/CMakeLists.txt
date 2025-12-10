add_headers_and_sources(perceptron ${CMAKE_CURRENT_SOURCE_DIR})

macro(add_test test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name} PRIVATE percept_core gtest gtest_main)
    target_include_directories(${test_name} PRIVATE "${PROJECT_SOURCE_DIR}/src")
endmacro()

add_test(percept_test)

