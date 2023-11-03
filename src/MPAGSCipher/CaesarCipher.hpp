#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

#include <cstddef>

class CaesarCipher {
    public:
        explicit CaesarCipher(const std::size_t key);
        explicit CaesarCipher(const std::string& key);
        
        std::size_t key_{0};
};



#endif