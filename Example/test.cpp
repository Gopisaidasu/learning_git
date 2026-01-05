#include"catch.hpp"
#include"String.h"

TEST_CASE("Check if string has even length", "[string]") {

    SECTION("Even length strings") {
        REQUIRE(isEvenLength("AB") == true);
        REQUIRE(isEvenLength("TEST") == true);
    }

    SECTION("Odd length strings") {
        REQUIRE(isEvenLength("A") == false);
        REQUIRE(isEvenLength("HELL") == false);
    }

    SECTION("Empty string") {
        REQUIRE(isEvenLength("") == true);
    }
}
