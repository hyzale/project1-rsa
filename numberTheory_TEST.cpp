
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE ("Testing modpower") {
    REQUIRE( modPower(2, 2, 3) == 1 );
    REQUIRE( modPower(2, 3, 3) == 2 );
    REQUIRE( modPower(12, 12, 123) == 66 );
    REQUIRE( modPower(10, 19, 1019) == 776 );
    REQUIRE( modPower(12345, 1234567, 123) == 66 );
    REQUIRE( modPower(12345, 123456789, 12345) == 0);
    ReallyLongInt* a = new ReallyLongInt(12);
    ReallyLongInt* b = new ReallyLongInt("12");
    ReallyLongInt* c = new ReallyLongInt(123);
    ReallyLongInt* d = new ReallyLongInt(modPower(*a, *b, *c));
    REQUIRE (d->toString() == "66" );
    delete a;
    delete b;
    delete c;
    delete d;
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
    ReallyLongInt* a = new ReallyLongInt(12);
    ReallyLongInt* b = new ReallyLongInt(941);
    ReallyLongInt* c = new ReallyLongInt(617);
    ReallyLongInt* d = new ReallyLongInt(718);
    REQUIRE( isPrime(*a) == false );
    REQUIRE( isPrime(*b) == true );
    REQUIRE( isPrime(*c) == true );
    REQUIRE( isPrime(*d) == false );
    delete a;
    delete b;
    delete c;
    delete d;
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

TEST_CASE("Testing ExtendedEuclid") {
    
    int x; int y; 

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