
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "numberTheory.hpp"

TEST_CASE ("Testing modpower") {
    REQUIRE( modPower(2, 2, 3) == 1 );
    REQUIRE( modPower(2, 3, 3) == 2 );
    REQUIRE( modPower(12, 12, 123) == 66 );
    REQUIRE( modPower(10, 19, 1019) == 776 );
    REQUIRE( modPower(12345, 1234567, 123) == 66 );
    REQUIRE( modPower(12345, 1234567, 123456789) == 100842075 );
    REQUIRE( modPower(12345, 123456789, 12345) == 0);
}

TEST_CASE ("Testing isPrime") {
    REQUIRE( isPrime(0) == false );
    REQUIRE( isPrime(1) == false );
    REQUIRE( isPrime(32) == false );

    REQUIRE( isPrime(25) == false );
    REQUIRE( isPrime(997) == true );
    REQUIRE( isPrime(2) == true );
    REQUIRE( isPrime(719) == true );
    REQUIRE( isPrime(83) == true );
    REQUIRE( isPrime(89) == true );

}

ull gcd(ull a, ull b) {
    return (b == 0) ? a : gcd(b, a % b);
}

TEST_CASE("Testing ExtendedEuclid") {
    
    ll x; ll y;

    SECTION ("Testing return value") {
        REQUIRE (extendEuclid(36, 48, &x, &y) == 12 );
        REQUIRE (extendEuclid(7, 49, &x, &y) == 7 );
        REQUIRE (extendEuclid(45, 81, &x, &y) == 9 );
        REQUIRE (extendEuclid(164, 88, &x, &y) == 4 );
    }

    SECTION ("Testing x and y") {
        extendEuclid(36, 48, &x, &y);
        REQUIRE( 36 * x + 48 * y == gcd(36, 48));

        extendEuclid(23, 46, &x, &y);
        REQUIRE( 23 * x + 46 * y == gcd(23, 46));

    }
}