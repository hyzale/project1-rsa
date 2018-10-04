#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <sstream>

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
        ReallyLongInt* c = new ReallyLongInt(-200);
        ReallyLongInt* d = new ReallyLongInt(-2002);
        ReallyLongInt* e = new ReallyLongInt(-2001);
        REQUIRE (a->equal(*b) == true );
        REQUIRE (c->equal(*d) == false );
        REQUIRE (e->equal(*d) == false );

        REQUIRE ((*a) == (*b));
        REQUIRE ((*a) != (*d));

        delete a;
        delete b;
        delete c;
        delete d;
        delete e;

    }

    SECTION ("Testing greater method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("1984");
        ReallyLongInt* c = new ReallyLongInt(-2001);
        ReallyLongInt* d = new ReallyLongInt(-2002);
        REQUIRE (a->greater(*b) == false );
        REQUIRE (c->greater(*d) == true );
        REQUIRE (a->greater(*c) == true );
        REQUIRE (d->greater(*b) == false );
        REQUIRE ((*a) <= (*b));
        REQUIRE ((*c) < (*b));
        REQUIRE ((*d) < (*b));
        REQUIRE ((*a) >= (*b));
        REQUIRE ((*b) > (*c));

        delete a;
        delete b;
        delete c;
        delete d;

    }
    SECTION ("Testing stream operator") {
        ReallyLongInt* a = new ReallyLongInt("-000002001");
        std::stringstream out;
        out << *a;
        REQUIRE (out.str() == "-2001" );
        delete a;
    }

    
    SECTION ("Testing absolute Add method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("9333");
        ReallyLongInt* c = new ReallyLongInt(-21);
        ReallyLongInt* d = new ReallyLongInt(-1997);
        ReallyLongInt* e = new ReallyLongInt(a->add(*b));
        ReallyLongInt* f = new ReallyLongInt(c->add(*d));
        REQUIRE (e->toString() == "11317" );
        REQUIRE (f->toString() == "-2018" );
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
        ReallyLongInt* c = new ReallyLongInt(21);
        ReallyLongInt* d = new ReallyLongInt(2018);
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
   
    SECTION ("Testing add method") {
        ReallyLongInt* a = new ReallyLongInt(-12999);
        ReallyLongInt* b = new ReallyLongInt(3322);
        ReallyLongInt* c = new ReallyLongInt(-2001);
        ReallyLongInt* d = new ReallyLongInt(2001);
        ReallyLongInt* e = new ReallyLongInt(*a);
        *e += *b;
        ReallyLongInt* f = new ReallyLongInt(c->add(*d));
        REQUIRE (e->toString() == "-9677" );
        REQUIRE (f->toString() == "0" );
        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
    }  
    
    SECTION ("Testing sub method") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("11317");
        ReallyLongInt* c = new ReallyLongInt(-21);
        ReallyLongInt* d = new ReallyLongInt(2018);
        ReallyLongInt* e = new ReallyLongInt(*a);
        *e -= *b;
        ReallyLongInt* f = new ReallyLongInt(c->sub(*d));

        REQUIRE (e->toString() == "-9333" );
        REQUIRE (f->toString() == "-2039" );
        *f -= *c;
        REQUIRE (f->toString() == "-2018" );
        ReallyLongInt* g = new ReallyLongInt(*a - *c);
        REQUIRE (g->toString() == "2005" );

        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
        delete g;
    }

    SECTION ("Testing increment and decrement") {
        ReallyLongInt* a = new ReallyLongInt(1984);
        ReallyLongInt* b = new ReallyLongInt("11317");
        ++*a;
        --*b;
        REQUIRE (a->toString() == "1985" );
        REQUIRE (b->toString() == "11316" );
        delete a;
        delete b;
    }
    SECTION ("Testing dummy increment and decrement") {
        ReallyLongInt a(1984);
        ReallyLongInt b("11317");
        ReallyLongInt c = a++;
        ReallyLongInt d = b--;
        REQUIRE (a.toString() == "1985" );
        REQUIRE (b.toString() == "11316" );
        REQUIRE (c.toString() == "1984" );
        REQUIRE (d.toString() == "11317" );

    }
    
    SECTION ("Testing multiplication") {
        ReallyLongInt* a = new ReallyLongInt(19845);
        ReallyLongInt* b = new ReallyLongInt("-11317");
        ReallyLongInt* c = new ReallyLongInt(-21);
        ReallyLongInt* d = new ReallyLongInt(0);
        ReallyLongInt* e = new ReallyLongInt(*a * *b);
        ReallyLongInt* f = new ReallyLongInt(c->mult(*d));
        REQUIRE (e->toString() == "-224585865" );
        REQUIRE (f->toString() == "0" );
        *c *= *e;
        REQUIRE (c->toString() == "4716303165" );

        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
    }

    SECTION ("Testing division") {
        ReallyLongInt* a = new ReallyLongInt(19223845);
        ReallyLongInt* b = new ReallyLongInt("-11317");
        ReallyLongInt* c = new ReallyLongInt(-22);
        ReallyLongInt* d = new ReallyLongInt(*a / *b);
        ReallyLongInt* e = new ReallyLongInt(*a % *b);
        ReallyLongInt* f = new ReallyLongInt(-22);
        ReallyLongInt* g = new ReallyLongInt(*c / *f);
        REQUIRE (d->toString() == "-1698" );
        REQUIRE (e->toString() == "7579" );
        *e /= *c;
        *d %= *c;
        REQUIRE (e->toString() == "-344" );
        REQUIRE (d->toString() == "-4" );
        REQUIRE (g->toString() == "1" );


        delete a;
        delete b;
        delete c;
        delete d;
        delete e;
        delete f;
        delete g;
    }

    SECTION ("Testing converting back to number") {
        ReallyLongInt* a = new ReallyLongInt(19223845);
        ReallyLongInt* b = new ReallyLongInt("-11317111111111111111111");
        REQUIRE (a->toLongLong() == 19223845);
        REQUIRE (b->toLongLong() == -33621890301194695);
    }



}