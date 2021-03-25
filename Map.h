//
// Created by alpacox on 25/03/21.
//
#include <SFML/Graphics.hpp>
#include "TileMap.h"
#include <vector>

#ifndef DRAGHI_E_SOTTERRANEI_MAP_H
#define DRAGHI_E_SOTTERRANEI_MAP_H


class Map {
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std::vector< sf::Vector2i> enemyPositions;
    void setUpInitialState();
    void setUpEnemyPositions();
    void setUpTiles();
public:
    std::vector< std::vector< TileMap *> > tiles;
    int gridLength;
    Map();

};


#endif //DRAGHI_E_SOTTERRANEI_MAP_H
