cmake_minimum_required(VERSION 3.2)

project(immer-range-v3-integration LANGUAGES CXX)

add_executable(main main.cpp)

set(RANGE_V3_NO_TESTING ON CACHE BOOLEAN "")
set(RANGE_V3_NO_EXAMPLE ON CACHE BOOLEAN "")
set(RANGE_V3_NO_PERF ON CACHE BOOLEAN "")
set(RANGE_V3_NO_HEADER_CHECK ON CACHE BOOLEAN "")

add_subdirectory(dependencies/immer)
add_subdirectory(dependencies/range-v3)

set_target_properties(main PROPERTIES CXX_STANDARD 14)

target_link_libraries(main PUBLIC immer)
target_link_libraries(main PUBLIC range-v3)
