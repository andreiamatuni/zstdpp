#include "helpers.hpp"

int main() {
    std::string 
        infile{"./input_stream_c.txt"}, 
        outfile{"./output_stream_c.zip"},
        input(  "this is a string that I want to compress into a smaller\n"
                "string. Just to make sure there is enough data in the\n"
                "compression buffer, I'm going to fill this string with a\n"
                "decent amount of content. Let's hope this works.\n"
        );
    fs::create_file(infile, zstdpp::utils::to_bytes(input));
    
    zstdpp::stream_compress(infile, outfile);
    
    auto const result_buffer = fs::read_file(outfile);
    print_compress_result(input, result_buffer);
    
    return 0;
  
}