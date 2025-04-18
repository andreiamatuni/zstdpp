#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <zstd.h>

namespace zstdpp {

using byte_t = std::uint8_t;
using compress_level_t = std::uint8_t;
using buffer_t = std::vector<byte_t>;
using string_t = std::string;
using size_buffer_t = std::size_t;

namespace utils{
    
    inline buffer_t to_bytes(std::string const& str){
        buffer_t bytes{};
        bytes.reserve(str.size());
    
        for (auto const& c : str) {
            bytes.push_back(c);
        }
        return bytes;
    }
    
    inline string_t to_string(buffer_t const& bytes){
        string_t str{};
        str.reserve(bytes.size());
        for (auto const& byte : bytes) {
            str.push_back(byte);
        }
        return str;
    }

} // namespace utils


/* Principal functions */

inline buffer_t compress( buffer_t const& data, compress_level_t compress_level = 3 ){
    size_t est_compress_size = ZSTD_compressBound(data.size());
    buffer_t comp_buffer{};
    comp_buffer.resize(est_compress_size);
    
    auto compress_size =
        ZSTD_compress((void*)comp_buffer.data(), est_compress_size, data.data(),
                      data.size(), compress_level);
        
    comp_buffer.resize(compress_size);
    comp_buffer.shrink_to_fit();
    return comp_buffer;
}

inline buffer_t decompress(buffer_t &data) {

  auto const est_decomp_size =
      ZSTD_getFrameContentSize(data.data(), data.size());

  buffer_t decomp_buffer{};
  decomp_buffer.resize(est_decomp_size);

  size_t const decomp_size = ZSTD_decompress(
      (void*)decomp_buffer.data(), est_decomp_size, data.data(), data.size());

  decomp_buffer.resize(decomp_size);
  decomp_buffer.shrink_to_fit();
  return decomp_buffer;
}

/* Re-Using compress/decompress functions with buffer_t for receive strings like data */

inline buffer_t compress(const string_t data, compress_level_t compress_level) {
    auto comp_buffer = utils::to_bytes(data);
    return compress(comp_buffer, compress_level);
}

inline buffer_t decompress(string_t data) {
    auto buffer = utils::to_bytes(data);
    return decompress(buffer);
}

/* In-place compression */
namespace inplace{
    
    inline size_buffer_t compress(const string_t data, string_t& buffer,
                                     compress_level_t compress_level = 3) {
      size_t est_compress_size = ZSTD_compressBound(data.size());
    
      buffer.resize(est_compress_size);
    
      auto compress_size = ZSTD_compress((void*)buffer.data(), est_compress_size,
                                         data.data(), data.size(), compress_level);
    
      buffer.resize(compress_size);
      buffer.shrink_to_fit();
    
      return buffer.size();
    }
    
    inline size_buffer_t decompress(const string_t& data,
                                       string_t& buffer) {
      auto const est_decomp_size =
          ZSTD_getFrameContentSize(data.data(), data.size());
    
      buffer.resize(est_decomp_size);
    
      size_t const decomp_size = ZSTD_decompress(
          (void*)buffer.data(), est_decomp_size, data.data(), data.size());
    
      buffer.resize(decomp_size);
      buffer.shrink_to_fit();
      return buffer.size();
    }
}


} // namespace zstdpp
