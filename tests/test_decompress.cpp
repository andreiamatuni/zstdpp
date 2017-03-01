#include <string>
#include <iostream>

#include "../zstdpp.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");

  auto compressed = zstdpp::compress(input, 22);

  std::cout << "original data: \n\n" << input << std::endl;

  std::cout << "  \noriginal size: " << input.size() << std::endl;
  std::cout << "compressed size: " << compressed.size() << std::endl;

  std::cout << "\n\ncompressed data: \n\n" << compressed << std::endl;

  auto decompressed = zstdpp::decompress(compressed);

  std::cout << "\ndecompressed size: " << decompressed.size() << std::endl;

  std::cout << "\ndecompressed data: \n\n" << decompressed << std::endl;

}
