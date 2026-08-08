

# ZSTDPP

Un contenedor de conveniencia en C++ de un solo archivo y de solo cabecera (header-only) alrededor de las funciones de compresión/descompresión de [libzstd](https://github.com/facebook/zstd).

Usamos objetos std::vector<std::uint8_t> y std::string como contenedores de memoria, y los pasamos a las funciones zstdpp::compress() y zstd::decompress(). Estas funciones devuelven un std::vector<std::uint8_t>, cuyos datos subyacentes son una versión comprimida o descomprimida del original.

También existen versiones de estas funciones de tipo in-place, que toman un búfer de memoria preasignado como argumento. Esto es útil si estás realizando muchas operaciones de compresión/descompresión en un bucle y deseas evitar asignaciones de memoria; estas funciones aceptan un std::string como argumento, actuando como un búfer de memoria preasignado para realizar la compresión/descompresión (en lugar de asignar un búfer nuevo en cada llamada a la función). Esto ayuda si estás realizando muchas operaciones de compresión/descompresión en un bucle.

# Ejemplo de uso 

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


# Ejemplo de uso de funciones in-place

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

### Para más ejemplos, consulta la carpeta tests.
