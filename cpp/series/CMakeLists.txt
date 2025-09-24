cmake_minimum_required(VERSION 3.10)
project(AnimeFilter)

find_package(OpenCV REQUIRED)
add_executable(anime_filter anime_filter.cpp)
target_link_libraries(anime_filter ${OpenCV_LIBS})
set_property(TARGET anime_filter PROPERTY CXX_STANDARD 11)
