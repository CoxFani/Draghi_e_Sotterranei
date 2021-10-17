//
// Created by alpacox on 25/03/21.
//

#include <SFML/Graphics.hpp>

#ifndef DRAGHI_E_SOTTERRANEI_TILEMAP_H
#define DRAGHI_E_SOTTERRANEI_TILEMAP_H

#include "Tile.h"

class Tile;

class TileMap {
public:

    TileMap(float gridSize, unsigned  width, unsigned  height);
    virtual ~TileMap();

    void update();
    void render(sf::RenderTarget& target);

    void addTile();
    void removeTile();

private:
    float gridSizeF;
    unsigned gridSizeU;
    sf::Vector2u maxSize;
    unsigned layers;
    std::vector< std::vector< std::vector<Tile> > > map;
};

#endif //DRAGHI_E_SOTTERRANEI_TILEMAP_H
