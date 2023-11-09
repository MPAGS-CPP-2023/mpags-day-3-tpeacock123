#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"



TEST_CASE("Correct encryption","[alphanumeric]"){

    std::string key{"5"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("AAAA",CipherMode::encrypt)};

    REQUIRE(outputText == "FFFF");
}

TEST_CASE("Correct decryption","[alphanumeric]"){

    std::string key{"5"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("FFFF",CipherMode::decrypt)};

    REQUIRE(outputText == "AAAA");
}

TEST_CASE("Encryption over the modulus","[alphanumeric]"){

    std::string key{"5"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("XXXX",CipherMode::encrypt)};

    REQUIRE(outputText == "CCCC");
}

TEST_CASE("Decryption over the modulus","[alphanumeric]"){

    std::string key{"5"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("CCCC",CipherMode::decrypt)};

    REQUIRE(outputText == "XXXX");
}

TEST_CASE("KEY > 26","[alphanumeric]"){

    std::string key{"27"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("AAA",CipherMode::encrypt)};

    REQUIRE(outputText == "BBB");
}

TEST_CASE("KEY > 26 decrypt","[alphanumeric]"){

    std::string key{"27"};
    CaesarCipher cKey {key};
    std::string outputText{cKey.runCaesarCipher("BBB",CipherMode::decrypt)};

    REQUIRE(outputText == "AAA");
}
