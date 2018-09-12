#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "reallyLongInt.hpp"

TEST_CASE ("Testing make int from string") {
    unsigned xSize;
    unsigned* a = rlIntMake("1223045", xSize);
    
    REQUIRE( xSize == 7 );
    REQUIRE( a[0] == 1 );
    REQUIRE( a[1] == 2 );
    REQUIRE( a[2] == 2 );
    REQUIRE( a[3] == 3 );
    REQUIRE( a[4] == 0 );
    REQUIRE( a[5] == 4 );
    REQUIRE( a[6] == 5 );

    delete[] a;

}

TEST_CASE("Testing int to string") {
    unsigned xSize;
    unsigned* a = rlIntMake("12345", xSize);
    REQUIRE (rlIntToString(a, xSize) == "12345");
    delete[] a;


}

TEST_CASE("Testing remove leading zero") {

    unsigned xSize;
    unsigned* a = rlIntMake("00000001223045", xSize);
    
    REQUIRE( xSize == 7 );
    REQUIRE( a[0] == 1 );
    REQUIRE( a[1] == 2 );
    REQUIRE( a[2] == 2 );
    REQUIRE( a[3] == 3 );
    REQUIRE( a[4] == 0 );
    REQUIRE( a[5] == 4 );
    REQUIRE( a[6] == 5 );

    delete[] a;
}

TEST_CASE("Testing equal function"){
    unsigned xSize; unsigned ySize;
    REQUIRE(rlIntEqual(rlIntMake("12345", xSize), xSize, rlIntMake("12345", ySize), ySize) == true); 
    REQUIRE(rlIntEqual(rlIntMake("0012345", xSize), xSize, rlIntMake("12345", ySize), ySize) == true); 
    REQUIRE(rlIntEqual(rlIntMake("1245", xSize), xSize, rlIntMake("12345", ySize), ySize) == false); 
    REQUIRE(rlIntEqual(rlIntMake("12345", xSize), xSize, rlIntMake("12346", ySize), ySize) == false); 

}
TEST_CASE("Testing greater function"){
    unsigned xSize; unsigned ySize;
    REQUIRE(rlIntGreater(rlIntMake("123456", xSize), xSize, rlIntMake("12345", ySize), ySize) == true); 
    REQUIRE(rlIntGreater(rlIntMake("0012345", xSize), xSize, rlIntMake("12345", ySize), ySize) == false); 
    REQUIRE(rlIntGreater(rlIntMake("1245", xSize), xSize, rlIntMake("12345", ySize), ySize) == false); 
    REQUIRE(rlIntGreater(rlIntMake("12346", xSize), xSize, rlIntMake("12345", ySize), ySize) == true); 
}
