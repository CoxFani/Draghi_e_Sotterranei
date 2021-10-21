//
// Created by alpacox on 25/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILEMAP_H
#define DRAGHI_E_SOTTERRANEI_TILEMAP_H

#include "Tile.h"


class Tile;

class TileMap {
public:

    TileMap(float gridSize, unsigned  width, unsigned  height, std::string texture_file);
    virtual ~TileMap();

    const sf::Texture* getTileSheet() const;

    void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect);
    void removeTile(const unsigned x, const unsigned y, const unsigned z);
    void saveToFile(const std::string file_name);
    void LoadFromFile(const std::string file_name);

    void update();
    void render(sf::RenderTarget& target);






private:
    float gridSizeF;
    unsigned gridSizeU;
    sf::Vector2u maxSize;
    unsigned layers;
    std::vector< std::vector< std::vector<Tile*> > > map;
    std::string  textureFile;
    sf::Texture tileSheet;
};

#endif //DRAGHI_E_SOTTERRANEI_TILEMAP_H
