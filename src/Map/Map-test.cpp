#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../Catch/catch.hpp" // header untuk unit-testing framework
#include "MapLoader.hpp"

TEST_CASE( "Cell are constructed", "[CELL]" ) {

    SECTION( "Default Constructor" ) {
        Cell C;
        CHECK( C.getType() == GRASS);
        CHECK( C.getObject() == '-');
    }
    SECTION( "User-Defined" ) {
        Cell C(SEA, 'w');
        CHECK( C.getType() == SEA );
        CHECK( C.getObject() == 'w');
    }
}

TEST_CASE( "Cell are updated", "[CELL]" ) {
    Cell C;

    SECTION( "update type" ) {
        C.setType(SEA);
        CHECK( C.getType() == SEA );
    } 
    SECTION( "update object" ) {
        C.setObject('P');
        CHECK( C.isPlayer() );
    }
    SECTION( "update object" ) {
        C.setObject('G');
        CHECK( C.isOccupied() );
    }
}

TEST_CASE( "Cell object moved", "[CELL]" ) {
    Cell Ci(GRASS, 'G');
    Cell Co, Ctemp;

    Ctemp.setObject(Ci.getObject());

    SECTION( "Target cell empty" ) {
        Ci >> Co;
        CHECK( Co.getObject() == 'G' );
        CHECK( Co.getObject() == Ctemp.getObject() );
        CHECK_FALSE( Ci.getObject() == Ctemp.getObject() );
    }

    SECTION( "Target cell occupied" ) {
        Co.setObject('f');
        Ci >> Co;
        CHECK_FALSE( Co.getObject() == 'G' );
        CHECK_FALSE( Co.getObject() == Ctemp.getObject());
        CHECK_FALSE( Ci.isEmpty() );
    }
}

// compile : g++ -o test Map-test.cpp Point.o Map.o Cell.o MapLoader.o
// test : 
// ./test 
// ./test [cell]