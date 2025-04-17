#include "helpers.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");

  auto compressed = zstdpp::compress(input, 22);
  print_compress_result(input, compressed);
}
