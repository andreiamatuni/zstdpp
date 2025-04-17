# ZSTDPP

A single file header only C++ convenience wrapper around the [libzstd](https://github.com/facebook/zstd) compression/decompression functions.

We use std::vector\<std::uint8_t\> & std::string objects as memory containers, and pass them into the zstdpp::compress() and zstd::decompress() functions. These functions return a std::vector\<std::uint8_t\>, who's underlying data is either a compressed or decompressed version of the original.

There are also in-place versions of the functions, which take a preallocated memory buffer as an argument. This is useful if you're doing a lot of compression/decompression in a loop, and you want to avoid allocatins, which accept a std::string as argument, acting as a preallocated memory buffer to perform compression/decompression (instead of allocating a new buffer on each function call). This helps if you're doing a lot of compression/decompression in a loop.

# Example usage 

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


# Example usage of in-place functions

```c++
#include <string>
#include <iostream>

#include "zstdpp.hpp"

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
```

### For more examples, check the tests folder.