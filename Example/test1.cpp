#include"catch.hpp"
#include"String.h"
/* Checking Room Temperature */
TEST_CASE("Checking Room Temperature", "[embedded]") {

    SECTION("Normal temperature below threshold") {
        REQUIRE(isTemperature(0) == 0);
        REQUIRE(isTemperature(10) == 0);
        REQUIRE(isTemperature(29) == 0);
    }

    SECTION("Temperature at threshold and above") {
        REQUIRE(isTemperature(31) == 1);
        REQUIRE(isTemperature(30) == 1);
        REQUIRE(isTemperature(100) == 1);
    }

    SECTION("Lower boundary violations") {
	INFO("lower temperature value");
        REQUIRE_THROWS_AS(isTemperature(-1), std::out_of_range);
        REQUIRE_THROWS_AS(isTemperature(-20), std::out_of_range);
        REQUIRE_THROWS_WITH(isTemperature(-20), "Warning lower range");
    }

    SECTION("Upper boundary violations") {
	INFO("upper temperature value");
        REQUIRE_THROWS_AS(isTemperature(101), std::out_of_range);
        REQUIRE_THROWS_AS(isTemperature(150), std::out_of_range);
        REQUIRE_THROWS_WITH(isTemperature(150), "Warning High range");
    }
}


