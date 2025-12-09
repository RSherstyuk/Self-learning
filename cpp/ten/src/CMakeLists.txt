add_headers_and_sources(src_ten ${CMAKE_CURRENT_SOURCE_DIR})
add_library(src_ten ${src_ten_headers} ${src_ten_sources})
target_include_directories(src_ten PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # Make headers public for src_ten

# Date.cpp and Date.h form a library.
add_library(ten_date STATIC Date.cpp)
target_include_directories(ten_date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# main.cpp is a standalone executable.
add_executable(ten_main main.cpp)
# Link ten_main with ten_date if it ever needs to use Date class.
# target_link_libraries(ten_main PRIVATE ten_date)
