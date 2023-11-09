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
