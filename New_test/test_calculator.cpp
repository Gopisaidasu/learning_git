#include "catch.hpp"
#include "calculator.h"

#include <string.h>
#include<iostream>

TEST_CASE("Modulo using generators", "[modulo]") {

    int a = GENERATE(2, 5, -3);
    int b = GENERATE(1, 2);

    CAPTURE(a, b);

    REQUIRE(modulo(a, b) == (a % b));
}


/* Generate with sections */
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

/* Factorial */
namespace
{
	int Factorial(size_t number)
	{
		return number <=1?number:Factorial(number-1)*number;
	}
}
TEST_CASE("Factorial","[fact]") {
	SECTION("Factorial of 0 is 1")
	{
		REQUIRE(Factorial(0)==1);
	}
	SECTION("Factorial of 1 and higher(pass)")
	{
		REQUIRE(Factorial(1)==1);
		REQUIRE(Factorial(3)==6);
		REQUIRE(Factorial(4)==25);
	}
}

/* Table */
TEST_CASE("tables", "[generators]") {
    auto data = GENERATE(table<char const*, int>({
        {"first", 5},
        {"second", 6},
        {"third", 5},
        {"etc...", 5}
    }));

    REQUIRE(strlen(std::get<0>(data)) == static_cast<size_t>(std::get<1>(data)));

 }

/*Consider 2 numbers of random odd number between range */
TEST_CASE("Chaining generators","[rand]") {
    auto i = GENERATE(take(2, filter([](int i) {
                              return i % 2 == 1;
                           }, random(-100, 100))));
    REQUIRE(i > -100);
    REQUIRE(i < 100);
    REQUIRE(i % 2 == 1);
}

/* Consider in range with value in repeat of 2 times*/
TEST_CASE("Range generator working example","[repeat]") {
    using Catch::Generators::repeat;
    using Catch::Generators::range;
    int i =GENERATE(repeat(2, range(1, 10, 2)));
    REQUIRE(i == 2 );
    REQUIRE(i >= 1);
    REQUIRE(i < 10);
}

/* map converts values into multiple of 10 and chunk group generated values 2 in container*/
TEST_CASE("map + chunk example") {
    using Catch::Generators::map;
    using Catch::Generators::chunk;
    using Catch::Generators::range;

    auto values = GENERATE(
        chunk(2,
            map([](int x) {
                return x * 10;
            }, range(1, 7))
        )
    );

        REQUIRE(values.size()<=2);
         for (int v : values) {
        REQUIRE(v % 10 == 0);
    }
}

/* Iterator*/
TEST_CASE("Iterator generator example","[IT]") {
static const std::vector<int> data = {1, 2, 3, 4};

    int value = GENERATE(from_range(data));

    REQUIRE(value >= 1);
}

/* Minimum and Maximum boundary */
TEST_CASE("Boundary test for setVolume", "[boundary]") {

    SECTION("Valid boundary values") {
        int input = GENERATE(0, 100);
        REQUIRE(setVolume(input) == input);
    }

    SECTION("Out-of-range values") {
        int input = GENERATE(-2, 101);
        REQUIRE(setVolume(input) == -1);
    }
}
/* Section */
TEST_CASE("Section showcase","[Another]") {
    std::cout << '1';
    SECTION("A") {
        std::cout << 'A';
        SECTION("a") { std::cout << 'a'; }
        SECTION("b") { std::cout << 'b'; }
    }
    SECTION("B") {
        std::cout << 'B';
        SECTION("a") { std::cout << 'a'; }
        SECTION("b") { std::cout << 'b';
        SECTION("c") { std::cout << 'c';}	}
    }
    std::cout << '\n';
}


