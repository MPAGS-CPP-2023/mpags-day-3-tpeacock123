#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"
#include <vector>


TEST_CASE("Help message display","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","-h"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.helpRequested == true);
}

TEST_CASE("version message display","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","--version"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.versionRequested == true);
}

TEST_CASE("input_file saved","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","-i","input"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.inputFile == "input");
}
TEST_CASE("output_file saved","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","-o","output"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.outputFile == "output");
}

TEST_CASE("correct Key","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","-k","5"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.cipherKey == "5");
}
TEST_CASE("Correct mode","[alphanumeric]"){
    ProgramSettings CLA {false, false, "","","",CipherMode::encrypt};
    const std::vector<std::string> cmdLineArgs{"filename","--decrypt"};

    processCommandLine(cmdLineArgs,CLA);
    REQUIRE(CLA.mode == CipherMode::decrypt);
}








