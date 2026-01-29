#include"catch.hpp"
#include"String.h"
/* String even or odd Length */
TEST_CASE("Check if string has even length", "[string]") {

    SECTION("Even length strings") {
        REQUIRE(isEvenLength("AB") == true);
        REQUIRE(isEvenLength("TEST") == true);
    }

    SECTION("Odd length strings") {
        REQUIRE(isEvenLength("HELL") == false);
        REQUIRE(isEvenLength("A") == false);
    }

    SECTION("Empty string") {
        REQUIRE(isEvenLength("") == true);
    }
}
/* Check strings are equal or not */
TEST_CASE("Check if two strings are equal", "[Equal]") {
	REQUIRE(isEqual("gopi","gopi")==1);
	REQUIRE(isEqual("sai","sia")==0);
	REQUIRE(isEqual(NULL, "abc") == -1);
	REQUIRE(isEqual("", "") == 1);
        REQUIRE(isEqual("A", "a") == 0);
}
/* Check given String Length */
TEST_CASE("Check Length of a String", "[Length]") {
	REQUIRE(isLength("gopi")==4);
	REQUIRE(isLength("gop")==3);
	REQUIRE(isLength("")==-1);
	REQUIRE(isLength(NULL)==-1);
}
/* Check given String is Palindrome or not */
TEST_CASE("Check if palindrome or not","[Palindrome]") {
	REQUIRE(isPalindrome("goog")==1);
	REQUIRE(isPalindrome("")==1);
	REQUIRE(isPalindrome("go")==0);
	REQUIRE(isPalindrome(NULL)==-1);
}
/* Checking char in string */
TEST_CASE("Check char is present in a string","[check]")
{
	REQUIRE(isTrue("advanced",'a')==1);
	REQUIRE(isTrue("embedded",'E')==0);
	REQUIRE(isTrue("",'e')==-1);
	REQUIRE(isTrue(NULL,'e')==-1);
	REQUIRE(isTrue("abc",'\0')==-1);
}
/* Checking string in a string */

TEST_CASE("Check string is present in a string","[str]")
{
	REQUIRE(isString("embedded","edd")==1);
	REQUIRE(isString("abcd","Bcd")==0);
	REQUIRE(isString("","abc")==-1);
	REQUIRE(isString("abc",NULL)==-1);
}
/* Checking char count in a string */

TEST_CASE("Check char count in a string","[count]")
{
	REQUIRE(countChar("abcdbe",'b')==2);
	REQUIRE(countChar("abcdbe",'f')==0);
	REQUIRE(isTrue("",'e')==-1);
	REQUIRE(isTrue(NULL,'e')==-1);
}
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
    }

    SECTION("Upper boundary violations") {
	INFO("upper temperature value");
        REQUIRE_THROWS_AS(isTemperature(101), std::out_of_range);
        REQUIRE_THROWS_AS(isTemperature(150), std::out_of_range);
    }
}


