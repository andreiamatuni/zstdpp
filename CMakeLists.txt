# Compatibility with CMake < 3.5 will be removed from a future version of CMake.
# (cmake 3.28.3)
cmake_minimum_required(VERSION 3.5)
project(zstdpp_tests CXX)

add_executable(test_compress tests/test_compress.cpp)
add_executable(test_compress_buffer tests/test_compress_buffer.cpp)
add_executable(test_decompress tests/test_decompress.cpp)
add_executable(test_decompress_buffer tests/test_decompress_buffer.cpp)
add_executable(test_inplace tests/test_inplace.cpp)

set_property(TARGET test_compress PROPERTY CXX_STANDARD 20)
set_property(TARGET test_compress_buffer PROPERTY CXX_STANDARD 20)
set_property(TARGET test_decompress PROPERTY CXX_STANDARD 20)
set_property(TARGET test_decompress_buffer PROPERTY CXX_STANDARD 20)
set_property(TARGET test_inplace PROPERTY CXX_STANDARD 20)

target_link_libraries(test_compress zstd)
target_link_libraries(test_compress_buffer zstd)
target_link_libraries(test_decompress zstd)
target_link_libraries(test_decompress_buffer zstd)
target_link_libraries(test_inplace zstd)