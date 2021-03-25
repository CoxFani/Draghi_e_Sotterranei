//
// Created by alpacox on 25/03/21.
//

#include "Map.h"

Map::Map(){
    gridLength = 8;
    setUpInitialState();
}

void Map::setUpInitialState() {
    exitPos = sf::Vector2i(1, 0);
    //TODO randomizzare spawn dell'eroe
    setUpEnemyPositions();
    setUpTiles();
}

void Map::setUpEnemyPositions() {
    enemyPositions.clear();
    //TODO randomizzare spawn dei nemici
}

void Map::setUpTiles() {
    tiles.clear();
    //TODO randomizzare struttura della mappa
}

