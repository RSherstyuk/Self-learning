# lru.h contains the implementation of lruCache, making it a header-only component.
# main.cpp is an executable that uses lruCache.
add_executable(ten_lru_example main.cpp)
target_include_directories(ten_lru_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
