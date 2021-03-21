#include "MapLoader.hpp"

Map* MapLoader::load(string filename) {
    ifstream infile(filename);
    string line;
    int i,j;
    int length = DEFAULT_LENGTH;
    int width = DEFAULT_WIDTH;

    Map *map = new Map();

    j = width;
    while (getline(infile, line)) {
        i = 0;
        while (line[i] != '\n' && line[i]) {
            map->at(i+1, j).setObject(line[i]);
            if(map->at(i+1, j).getObject() == '-' || map->at(i+1, j).getObject() == 'P')
            {
                map->at(i+1, j).setType(GRASS);
            }
            else
            {
                map->at(i+1, j).setType(SEA);
            }
            i++;
        }
        j--;
    }

    return map;
}