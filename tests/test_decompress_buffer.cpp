#include "helpers.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");
  
  auto compressed = zstdpp::compress(input, 22);
  
  // Decompress with data like string
  auto buffer = zstdpp::utils::to_string(compressed);
  auto decompressed = zstdpp::decompress(buffer);

  print_decompress_result(compressed, decompressed);
  
}
