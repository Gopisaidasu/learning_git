#include "catch.hpp"
#include "calculator.h"
#include <string>

/* Contains */
TEST_CASE("combining matchers","[contains][matcher]") {
    using Catch::Matchers::Contains;
    SECTION("Require that"){
    REQUIRE_THAT(
        description(),
        Contains("MongoDB") || !Contains("web scale")
    );
    }
    SECTION("Check that"){
    CHECK_THAT(description(),Contains("MongoDB is"));
    CHECK_THAT(description(),Contains("Mongo"));
    }
    SECTION("Require false "){
    REQUIRE_FALSE(1);
    REQUIRE_FALSE(0);
    }
    SECTION("Check false "){
    CHECK_FALSE(1);
    CHECK_FALSE(0);
    }


}

TEST_CASE("Throw an error","[exception]") {
	SECTION("No throw")
	{
	REQUIRE_NOTHROW(divide(10, 0));
	REQUIRE_NOTHROW(divide(10, 2));
	}
	SECTION("No throw using Check")
	{
	CHECK_NOTHROW(divide(10, 0));
	CHECK_NOTHROW(divide(10, 2));
	}
	SECTION(" throws")
	{
	REQUIRE_THROWS(divide(10, 0));
	REQUIRE_THROWS(divide(10, 2));
	}
	SECTION(" throws as")
	{
	REQUIRE_THROWS_AS(divide(10, 0),std::runtime_error);
	REQUIRE_THROWS_AS(divide(10, 0),std::logic_error);
	}
	SECTION(" throws as")
	{
	REQUIRE_THROWS_WITH(divide(10, 0),"divide by zero");
	REQUIRE_THROWS_WITH(divide(10, 0),"error");
	}

}

/* Unordered Equals */
TEST_CASE("unorderd  matchers","[matcher]") {
    using Catch::Matchers::UnorderedEquals;
    std::vector<int> vec{0,1,2,3,4};

    std::shuffle(vec.begin(), vec.end(), std::random_device{}); 
    REQUIRE_THAT(vec,UnorderedEquals<int>({0,1,2,3,4,5}));
 }

/*built in */
TEST_CASE("StartsWith and EndsWith example","[built]") {
    using Catch::Matchers::StartsWith;
    using Catch::Matchers::EndsWith;

    std::string version = "MongoDB is v6.0";

    REQUIRE_THAT(version, StartsWith("MongoDB"));
    REQUIRE_THAT(version, EndsWith("V6.0"));
}

/* Equals */
TEST_CASE(" matchers","[vector_matcher]") {
    using Catch::Matchers::Equals;
    std::vector<int> vec{0,1,2,3,4};

    std::shuffle(vec.begin(), vec.end(), std::random_device{}); 
    REQUIRE_THAT(vec ,Equals<int>({0,1,2,3,4,}));
}

/* Matches*/
TEST_CASE(" matcher","[string_matcher]") {
using Catch::Matchers::Matches;

REQUIRE_THAT("MongoDB v6", Matches("MongoDB v[0-7]"));
}



TEST_CASE("Vector contains example","[vectorcontains]") {
    using Catch::Matchers::VectorContains;
   
    std::vector<int> values = {1, 3, 5, 7};

    REQUIRE_THAT(values, VectorContains(5));
}






























TEST_CASE("predicate character","[predicate]"){

    using Catch::Matchers::Predicate;

    REQUIRE_THAT("Hello olleH",
             Predicate<std::string>(
                 [] (std::string const& str) -> bool { return str.front() == str.back(); },
                 "First and last character should be equal")

);

}

struct parse_error : std::exception {
    int line() const { return 1; }
};

void parse(const char*) {
    throw parse_error{};
}

TEST_CASE("parse throws parse_error","[error]") {
    REQUIRE_THROWS_MATCHES(
        parse("abc"),
        parse_error,
        Catch::Matchers::Predicate<parse_error>(
            [](parse_error const& err) {
                return err.line() == 1;
            }
        )
    );
}


