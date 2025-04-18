#include <string>
#include "../zstdpp.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");
  // we're going to use the in-place functions, so we need to allocate a buffer
  std::string buffer_compress{}, buffer_decompress{};
  
  auto compressed_size = zstdpp::inplace::compress(input, buffer_compress, 22);

  auto decompressed_size = zstdpp::inplace::decompress(buffer_compress, buffer_decompress);
  
}