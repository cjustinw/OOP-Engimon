#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../Catch/catch.hpp" // header untuk unit-testing framework
#include "Point.hpp"

TEST_CASE( "Point are constructed", "[POINT]" ) {
    Point P1;
    
    REQUIRE( P1.getX() == 0 );
    REQUIRE( P1.getY() == 0 );

    SECTION("user-defined constructor") {
        Point P2(P1.getX(), P1.getY());

        REQUIRE( P2.getX() == 0 );
        REQUIRE( P2.getY() == 0 );

        SECTION("Point operator== overloading") {
            REQUIRE( (P1==P2) == true );
        }
    }
}

TEST_CASE( "Point are updated", "[POINT]") {
    Point P1(0,3);

    REQUIRE( P1.getX() == 0 );
    REQUIRE( P1.getY() == 3 );

    SECTION( "Substract X by 1" ) {
        P1.subX();
        REQUIRE( P1.getX() == X_MIN_SIZE );
    }
    SECTION( "Add X by 1" ) {
        P1.addX();
        REQUIRE( P1.getX() == 1 );
    }
    SECTION( "Substract Y by 1" ) {
        P1.subY();
        REQUIRE( P1.getY() == 2 );
    }
    SECTION( "Add Y by 1" ) {
        P1.addY();
        REQUIRE( P1.getY() == 4 );
    }
    SECTION( "Setter X" ) {
        P1.setX(10);
        REQUIRE( P1.getX() == 10 );
    }
    SECTION( "Setter Y" ) {
        P1.setY(50);
        REQUIRE( P1.getY() == 50 );
    }
}

// compile : g++ -o test Point-test.cpp Point.o
// test : ./test 