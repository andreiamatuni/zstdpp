#include <iostream>
#include <string.h>

#include "zstd.h"


namespace zstdpp {

inline std::string compress(const std::string data, int compress_level) {

  size_t est_compress_size = ZSTD_compressBound(data.size());

  std::string comp_buffer{};
  comp_buffer.resize(est_compress_size);

  auto compress_size =
      ZSTD_compress((void*)comp_buffer.data(), est_compress_size, data.data(),
                    data.size(), compress_level);

  comp_buffer.resize(compress_size);
  comp_buffer.shrink_to_fit();

  return comp_buffer;
}

inline std::string decompress(std::string data) {

  auto const est_decomp_size =
      ZSTD_getDecompressedSize(data.data(), data.size());

  std::string decomp_buffer{};
  decomp_buffer.resize(est_decomp_size);

  size_t const decomp_size = ZSTD_decompress(
      (void*)decomp_buffer.data(), est_decomp_size, data.data(), data.size());

  decomp_buffer.resize(decomp_size);
  decomp_buffer.shrink_to_fit();
  return decomp_buffer;
}

inline std::string& buff_compress(const std::string data, std::string& buffer,
                                 int compress_level) {
  size_t est_compress_size = ZSTD_compressBound(data.size());

  buffer.resize(est_compress_size);

  auto compress_size = ZSTD_compress((void*)buffer.data(), est_compress_size,
                                     data.data(), data.size(), compress_level);

  buffer.resize(compress_size);
  buffer.shrink_to_fit();

  return buffer;
}

inline std::string& buff_decompress(const std::string& data,
                                   std::string& buffer) {
  auto const est_decomp_size =
      ZSTD_getDecompressedSize(data.data(), data.size());

  buffer.resize(est_decomp_size);

  size_t const decomp_size = ZSTD_decompress(
      (void*)buffer.data(), est_decomp_size, data.data(), data.size());

  buffer.resize(decomp_size);
  buffer.shrink_to_fit();
  return buffer;
}
}
