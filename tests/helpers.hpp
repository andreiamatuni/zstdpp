#pragma once
#include <iostream>
#include <bitset>
#include <string>

#include "../zstdpp.hpp"

/* Utils types */
using byte_t = zstdpp::byte_t;
using buffer_t = zstdpp::buffer_t;

namespace fs{

    inline void create_file(std::string const& filename, buffer_t const& buffer){
        std::ofstream file(filename, std::ios::binary);
        file.write((char*)buffer.data(), buffer.size());
    }

    inline size_t get_file_size(std::ifstream& file){
        file.seekg(0, std::ios::end);
        auto const file_size = file.tellg();
        file.seekg(0, std::ios::beg);
        return file_size;
    }
    
    inline size_t read_file_on(const std::string filename, buffer_t& buffer){
        std::ifstream file(filename, std::ios::binary);
        auto const file_size = get_file_size(file);
        buffer.resize(file_size);
        file.read((char*)buffer.data(), file_size);
        return file_size;
    }
    
    inline buffer_t read_file(std::string const& filename){
        buffer_t buffer{};
        read_file_on(filename,buffer);
        return buffer;
    }
    
    inline void write_file(std::string const& filename, buffer_t const& buffer){
        std::ofstream file(filename, std::ios::binary);
        file.write((char*)buffer.data(), buffer.size());
    }
    
} // namespace fs

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
