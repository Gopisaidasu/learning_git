#include "catch.hpp"

#include "calculator.h"

/* ---------- ADDITION TESTS ---------- */
TEST_CASE("Addition", "[add]") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-2, 3) == 1);
    REQUIRE(add(-2, -3) == -5);
}

/* ---------- SUBTRACTION TESTS ---------- */
TEST_CASE("Subtraction", "[subtract]") {
    REQUIRE(subtract(5, 3) == 2);
    REQUIRE(subtract(3, 5) == -2);
    REQUIRE(subtract(0, 0) == 0);
}

/* ---------- MULTIPLICATION TESTS ---------- */
TEST_CASE("Multiplication", "[multiply]") {
    REQUIRE(multiply(2, 3) == 6);
    REQUIRE(multiply(-2, 3) == -6);
    REQUIRE(multiply(0, 5) == 0);
}

/* ---------- DIVISION TESTS ---------- */
TEST_CASE("Division", "[divide]") {
    REQUIRE(divide(6, 3) == 2);
    REQUIRE(divide(5, 2) == Approx(2.5));
    REQUIRE(divide(2, 5) == 0.40);
   REQUIRE(divide(5, 0) == 0);
}

