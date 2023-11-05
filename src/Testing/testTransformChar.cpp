#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are uppercase","[alphanumeric]"){
    const std::string upper{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const std::string lower{"abcdefghijklmnopqrstuvwxyz"};

    for (size_t i = 0; i < upper.size(); i++)
    {
        REQUIRE( transformChar(lower[i]) == std::string{upper[i]} );
    }
}

