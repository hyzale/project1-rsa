
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "numberTheory.hpp"

TEST_CASE ("Testing modpower") {
    REQUIRE( modpower(2, 2, 3) == 1 );
    REQUIRE( modpower(2, 3, 3) == 2 );
    REQUIRE( modpower(12, 12, 123) == 66 );
    REQUIRE( modpower(10, 19, 1019) == 776 );
    REQUIRE( modpower(12345, 1234567, 123) == 66 );
    REQUIRE( modpower(12345, 1234567, 123456789) == 100842075 );
    REQUIRE( modpower(12345, 123456789, 12345) == 0);
}

TEST_CASE ("Testing isPrime") {
    REQUIRE( isPrime(0) == false );
    REQUIRE( isPrime(1) == false );
    REQUIRE( isPrime(25) == false );
    REQUIRE( isPrime(997) == true );
    REQUIRE( isPrime(2) == true );
    REQUIRE( isPrime(719) == true );
}