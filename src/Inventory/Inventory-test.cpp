#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../Catch/catch.hpp" // header untuk unit-testing framework
#include "Inventory.hpp"


TEST_CASE( "Inventory CRUD", "[INVENTORY]" ) {
    Inventory<char> Inv;
    char c = 'c';
    char o = 'o';
    char l = 'l';

    REQUIRE( Inv.getNumOfElement() == 0 );

    Inv.add(c);
    Inv.add(o);
    Inv.add(o);
    Inv.add(l);

    REQUIRE( Inv.getNumOfElement() == 4 );

    SECTION( "Inventory Read" ) {
        CHECK( Inv[1] == 'o' );
    }
    SECTION( "Inventory Update" ) {
        Inv.delAt(2);

        CHECK( Inv.getNumOfElement() == 3 );
        CHECK( Inv[2] == 'l' );
    }
}