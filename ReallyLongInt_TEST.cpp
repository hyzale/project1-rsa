#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

#include "ReallyLongInt.hpp"

unsigned ReallyLongInt::getNumDigits() {
    return numDigits;
}

bool ReallyLongInt::getIsNeg() {
    return isNeg;
}

TEST_CASE ("Test for ReallyLongInt class") {

    SECTION ("Testing remove leading zero") {
        ReallyLongInt* a = new ReallyLongInt("-000002001");
        ReallyLongInt* b = new ReallyLongInt("-00000");
        REQUIRE (a->getIsNeg() == true );
        REQUIRE (b->getIsNeg() == false );
        REQUIRE (a->getNumDigits() == 4 );
        REQUIRE (b->getNumDigits() == 1 );
        delete a;
        delete b;
    }
    
    SECTION ("Testing tostring") {
        ReallyLongInt* a = new ReallyLongInt("-000002001");
        ReallyLongInt* b = new ReallyLongInt("-00000");
        REQUIRE (a->toString() == "-2001" );
        REQUIRE (b->toString() == "0" );
        delete a;
        delete b;
    }

    SECTION ("Testing constructor from number") {
        ReallyLongInt* a = new ReallyLongInt(-2001);
        ReallyLongInt* b = new ReallyLongInt(-0);
        ReallyLongInt* c = new ReallyLongInt(2001);
        REQUIRE (a->getIsNeg() == true );
        REQUIRE (b->getIsNeg() == false );
        REQUIRE (c->getIsNeg() == false );
        REQUIRE (a->getNumDigits() == 4 );
        REQUIRE (b->getNumDigits() == 1 );
        REQUIRE (c->getNumDigits() == 4 );
        REQUIRE (a->toString() == "-2001" );
        REQUIRE (b->toString() == "0" );
        REQUIRE (c->toString() == "2001" );
        delete a;
        delete b;
        delete c;
    }
    SECTION ("Testing copy constructor") {
        ReallyLongInt* a = new ReallyLongInt();
        ReallyLongInt* b = new ReallyLongInt(*a);
        delete a;
        a = new ReallyLongInt(2003);
        ReallyLongInt* c = new ReallyLongInt(-2001);
        ReallyLongInt* d = new ReallyLongInt(*c);
        REQUIRE (b->getIsNeg() == false );
        REQUIRE (c->getIsNeg() == true );
        REQUIRE (b->getNumDigits() == 1 );
        REQUIRE (c->getNumDigits() == 4 );
        REQUIRE (b->toString() == "0" );
        REQUIRE (c->toString() == "-2001" );
        delete a;
        delete b;
        delete c;
        delete d;

    }

    SECTION ("Testing equal method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("1984");
        ReallyLongInt* c = new ReallyLongInt(-2001);
        ReallyLongInt* d = new ReallyLongInt(-2002);
        REQUIRE (a->equal(*b) == true );
        REQUIRE (c->equal(*d) == false );
        delete a;
        delete b;
        delete c;
        delete d;

    }

    SECTION ("Testing greater method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("1984");
        ReallyLongInt* c = new ReallyLongInt(-2001);
        ReallyLongInt* d = new ReallyLongInt(-2002);
        REQUIRE (a->greater(*b) == false );
        REQUIRE (c->greater(*d) == true );
        delete a;
        delete b;
        delete c;
        delete d;

    }  
    
    SECTION ("Testing absolute Add method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("9333");
        ReallyLongInt* c = new ReallyLongInt(-21);
        ReallyLongInt* d = new ReallyLongInt(-1997);
        ReallyLongInt* e = new ReallyLongInt(a->add(*b));
        ReallyLongInt* f = new ReallyLongInt(c->add(*d));
        REQUIRE (e->toString() == "11317" );
        REQUIRE (f->toString() == "2018" );
        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
    }

    SECTION ("Testing absolute sub method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("11317");
        ReallyLongInt* c = new ReallyLongInt(-21);
        ReallyLongInt* d = new ReallyLongInt(-2018);
        ReallyLongInt* e = new ReallyLongInt(a->sub(*b));
        ReallyLongInt* f = new ReallyLongInt(c->sub(*d));
        REQUIRE (e->toString() == "-9333" );
        REQUIRE (f->toString() == "-1997" );
        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
    }

}