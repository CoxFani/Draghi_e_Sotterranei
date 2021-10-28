//
// Created by alpacox on 25/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILEMAP_H
#define DRAGHI_E_SOTTERRANEI_TILEMAP_H

#include "Tile.h"
#include "GameCharacter.h"


class Tile;
class GameCharacter;

class TileMap {
public:

    TileMap(float gridSize, unsigned  width, unsigned  height, std::string texture_file);
    virtual ~TileMap();

    const sf::Texture* getTileSheet() const;

    void addTile(const unsigned x, const unsigned y, const unsigned z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
    void removeTile(const unsigned x, const unsigned y, const unsigned z);
    void saveToFile(const std::string file_name);
    void loadFromFile(const std::string file_name);

    void updateCollision(GameCharacter* gameCharacter);

    void update();
    void render(sf::RenderTarget& target, GameCharacter* gameCharacter = nullptr);

private:
    float gridSizeF;
    unsigned gridSizeU;
    sf::Vector2u maxSizeWorldGrid;
    sf::Vector2f maxSizeWorldF;
    unsigned layers;
    std::vector< std::vector< std::vector<Tile*> > > map;
    std::string  textureFile;
    sf::Texture tileSheet;
    sf::RectangleShape collisionBox;

    void clear();
};

#endif //DRAGHI_E_SOTTERRANEI_TILEMAP_H
