#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <vector>
#include <cstddef>
#include "CipherMode.hpp"

class CaesarCipher {

    public:
        explicit CaesarCipher(const std::size_t key);
        explicit CaesarCipher(const std::string& key);

        std::string runCaesarCipher(const std::string& inputText, 
                            CipherMode mode);
    
    private:
        std::size_t key_{0};
        const std::vector<char> alphabet_ = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        };
        
    

#endif