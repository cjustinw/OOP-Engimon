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

TEST_CASE( "Map is constructed", "[MAP]" ) {
    Map map;
    Point P(1,1);

    REQUIRE( map.getLength() == DEFAULT_LENGTH );
    REQUIRE( map.getWidth() == DEFAULT_WIDTH );
    REQUIRE( map.getSize() == DEFAULT_WIDTH*DEFAULT_LENGTH );
    REQUIRE( (map.getPlayerPosition() == P) );

    SECTION( "Copy Constructor" ) {
        Map* newMap = new Map(map);

        CHECK( newMap->getLength() == map.getLength() );
        CHECK( newMap->getWidth() == map.getWidth() );

        SECTION( "Destructor" ) {
            delete newMap;

            CHECK( map.at(1,1).isPlayer());
        }
    }
    SECTION( "Operator Assignment" ) {
        Map newMap(Point(5,5));

        CHECK( ( newMap.getPlayerPosition() == Point(5,5) ) );

        map = newMap;

        CHECK( (map.getPlayerPosition() == P) == false);
        CHECK( ( map.getPlayerPosition() == Point(5,5) ) );
    }
}

TEST_CASE( "Map is updated", "[MAP]" ) {
    Map m;

    m.setLength(10);
    REQUIRE( m.getLength() == 10 );
    m.setWidth(100);
    REQUIRE( m.getWidth() == 100 );
}

TEST_CASE( "Map & Cell", "[MAP][CELL]" ) {
    Map map;
    Point player(1,1);

    REQUIRE( map.at(player).isPlayer() );

    map.at(10,10).setObject('W');
    REQUIRE( map.at(10,10).isOccupied() );

    Point next(5,5);
    map.moveObject(player, next);

    REQUIRE( (map.getPlayerPosition() == next) == true);
}

TEST_CASE( "MapLoader", "[MAPLOADER][MAP][CELL]" ) {
    MapLoader mapLoader;
    Map * map;

    map = mapLoader.load("testfile.txt");

    REQUIRE( (map->getPlayerPosition() == Point(1,15)) );
    REQUIRE( map->at(25,12).getType() == SEA );
}

// compile : g++ -o test Map-test.cpp Point.o Map.o Cell.o MapLoader.o
// test : 
// ./test 
// ./test [cell]