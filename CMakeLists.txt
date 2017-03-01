project(zstdpp_tests CXX)
cmake_minimum_required(VERSION 3.2)



add_executable(test_compress tests/test_compress.cpp)
add_executable(test_decompress tests/test_decompress.cpp)

set_property(TARGET test_compress PROPERTY CXX_STANDARD 14)
set_property(TARGET test_decompress PROPERTY CXX_STANDARD 14)
target_link_libraries(test_compress zstd)
target_link_libraries(test_decompress zstd)
