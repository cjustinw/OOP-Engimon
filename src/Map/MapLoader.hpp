#ifndef _MAPLOADER_HPP_
#define _MAPLOADER_HPP

#include "Map.hpp"
#include <fstream>

class MapLoader{
private:
public:
    // filename adalah nama file eksternal
    // yang berisi map, default adalah map.txt
    Map* load(string filename = "map.txt");
};

#endif