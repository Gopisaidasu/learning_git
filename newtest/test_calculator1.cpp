#include "catch.hpp"

#include "calculator.h"
#include <algorithm>
#include <random>
#include <string>
/*
TEST_CASE("Modulo using generators", "[modulo][generator]") {

    int a = GENERATE(2, 5, -3);
    int b = GENERATE(1, 2);
    
    CAPTURE(a, b);

    REQUIRE(modulo(a, b) == (a % b));
}
*/
TEST_CASE("Generator", "[modulos]") {

    int a = GENERATE(2,1);
    int b = GENERATE(3);
    SECTION("A")
    {
    REQUIRE(modulo(a, b) == (a % b));
    }
    SECTION("B")
    {
    REQUIRE(modulo(a, b) == (a % b));
    }
}
TEST_CASE("combining matchers","[contains][matcher]") {
    using Catch::Matchers::Contains;

    REQUIRE_THAT(
        description(),
        Contains("MongoDB") || !Contains("web scale")
    );
}

TEST_CASE("unorderd  matchers","[matcher]") {
    using Catch::Matchers::UnorderedEquals;
    std::vector<int> vec{0,1,2,3,4};

    std::shuffle(vec.begin(), vec.end(), std::random_device{}); 
    REQUIRE_THAT(vec,UnorderedEquals<int>({0,1,2,3,4,5}));
 }

TEST_CASE(" matchers","[matcher]") {
    using Catch::Matchers::Equals;
    std::vector<int> vec{0,1,2,3,4};

    std::shuffle(vec.begin(), vec.end(), std::random_device{}); 
    REQUIRE_THAT(vec ,Equals<int>({0,1,2,3,4,}));
 }
TEST_CASE("Multiplication", "[multiply]") {
    REQUIRE(multiply(2, 3) == 6);
    REQUIRE(multiply(-2, 3) == -6);
}

