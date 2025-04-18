#pragma once
#include <iostream>
#include <bitset>
#include <string>

#include "../zstdpp.hpp"

/* Utils types */
using byte_t = zstdpp::byte_t;
using buffer_t = zstdpp::buffer_t;

inline double ratio(std::size_t compressed_size, std::size_t decompressed_size){
    return ((double)compressed_size / (double)decompressed_size) * 100.0;
}

inline void print_bytes(buffer_t const& buffer){
    for (auto const& byte : buffer) {
        std::cout << std::bitset<sizeof(byte)*8>(byte) << " ";
    }
}

inline void print_compress_result(std::string const& original_buffer, buffer_t const& result_buffer){
    std::cout << "\nOriginal Data: " << original_buffer << " (size: " << original_buffer.size() << ")" << std::endl;
    std::cout << "Compressed Data: ";
    print_bytes(result_buffer);
    std::cout << "(size: " << result_buffer.size() << ")" << std::endl;
    
    std::cout << "Ratio: " << ratio(result_buffer.size(), original_buffer.size()) << std::endl;
}

inline void print_decompress_result(buffer_t const& original_buffer, buffer_t const& result_buffer){
    std::cout << "\nOriginal Data: \n";
    print_bytes(original_buffer);
    std::cout << " (size: " << original_buffer.size() << ")" << std::endl;
    std::cout << "Decompressed Data: \n" << zstdpp::utils::to_string(result_buffer) << " (size: " << result_buffer.size() << ")" << std::endl;
    
    std::cout << "Ratio: " << ratio(original_buffer.size(), result_buffer.size()) << std::endl;
}
