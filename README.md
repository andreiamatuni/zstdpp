# zstdpp

A single file header only C++ convenience wrapper around the [libzstd](https://github.com/facebook/zstd)
compression/decompression functions.

We use std::string objects as memory containers, and pass them into the zstdpp::compress() and
zstd::decompress() functions. These functions return a std::string, who's underlying data is either
a compressed or decompressed version of the original.

There are also buffered versions of these functions, which accept a std::string as argument, acting as
a preallocated memory buffer to perform compression/decompression (instead of allocating a new buffer on
each function call). This helps if you're doing a lot of compression/decompression in a loop.

## example usage

```c++
#include <string>
#include <iostream>

#include "zstdpp.hpp"

int main() {
  std::string input("this is a string that I want to compress into a smaller\n"
                    "string. Just to make sure there is enough data in the\n"
                    "compression buffer, I'm going to fill this string with a\n"
                    "decent amount of content. Let's hope this works.\n");

  auto compressed = zstdpp::compress(input, 22);

  auto decompressed = zstdpp::decompress(compressed);

}
```
