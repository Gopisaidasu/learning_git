#include "catch.hpp"

#include "calculator.h"

/* ---------- ADDITION TESTS ---------- */
TEST_CASE("Addition", "[add]") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-2, -3) == -5);
    REQUIRE(add(2.5, 3) == 5.50);
    REQUIRE(add(-2, 3) == 1);
    REQUIRE(add(0, 3) == 3);
}

/* ---------- SUBTRACTION TESTS ---------- */
TEST_CASE("Subtraction", "[subtract]") {
    CHECK(subtract(5, 3) == 2);
    CHECK (subtract(3, 5) == -2);
    CHECK(subtract(3, -5) == 8);
    CHECK(subtract(3, 0) == 3);
    CHECK(subtract(0, 3) == -3);
    CHECK(subtract(2.5, 1) == 1.5);
}

/* ---------- MULTIPLICATION TESTS ---------- */
TEST_CASE("Multiplication", "[multiply]") {
    REQUIRE(multiply(2, 3) == 6);
    REQUIRE(multiply(5, 0) == 0);
    REQUIRE(multiply(5, -1) == -5);
    REQUIRE(multiply(-5, -1) == 5);
    REQUIRE(multiply(2.2, 1.2) == 2.64);
}

/* ---------- DIVISION TESTS ---------- */
TEST_CASE("Division", "[divide]") {
    REQUIRE(divide(6, 3) == 2.0);
    REQUIRE(divide(2, 5) == 0.40);
    REQUIRE(divide(-8,-2) == 4);
    REQUIRE(divide(-8,2) == -4);
    REQUIRE(divide(2.5, 2) == 1.25);
    REQUIRE_THROWS_AS(divide(2, 0), std::runtime_error);
	
}

/* ---------- Modulus TESTS ---------- */
TEST_CASE("Modulo operation", "[modulo]") {
    REQUIRE(modulo(5, 2) == 1);
    REQUIRE(modulo(0, 5) == 0);
    REQUIRE(modulo(-5, 2) == -1);
    REQUIRE(modulo(5, -2) == 1);
    REQUIRE(modulo(-5, -2) == -1);
    REQUIRE(modulo(2, 0) == 0);
}
