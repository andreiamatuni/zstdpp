#include "helpers.hpp"

int main() {
    std::string 
        infile{"./input_stream_d.zip"}, 
        outfile{"./output_stream_d.txt"},
        input(  "this is a string that I want to compress into a smaller\n"
                "string. Just to make sure there is enough data in the\n"
                "compression buffer, I'm going to fill this string with a\n"
                "decent amount of content. Let's hope this works.\n"
        );
    auto buffer = zstdpp::compress(input, 22);
    fs::create_file(infile, buffer);
    
    zstdpp::stream_decompress(infile, outfile);
    
    auto const result_buffer = fs::read_file(outfile);
    print_decompress_result(buffer, result_buffer);
    
    return 0;
  
}