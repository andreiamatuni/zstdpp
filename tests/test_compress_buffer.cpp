#include "helpers.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");
  
  // Compress with data like buffer of bytes
  auto buffer = zstdpp::utils::to_bytes(input);
  auto compressed = zstdpp::compress(buffer, 22);

  print_compress_result(input, compressed);
}
