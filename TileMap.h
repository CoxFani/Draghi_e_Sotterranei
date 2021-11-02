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

    TileMap(float gridSize, int  width, int  height, std::string texture_file);
    virtual ~TileMap();

    const sf::Texture* getTileSheet() const;

    void addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
    void removeTile(const int x, const int y, const int z);
    void saveToFile(const std::string file_name);
    void loadFromFile(const std::string file_name);

    void updateCollision(GameCharacter* gameCharacter, const float& dt);

    void update();
    void render(sf::RenderTarget& target, GameCharacter* gameCharacter = nullptr);

private:
    float gridSizeF;
    int gridSizeI;
    sf::Vector2i maxSizeWorldGrid;
    sf::Vector2f maxSizeWorldF;
    int layers;
    std::vector< std::vector< std::vector<Tile*> > > map;
    std::string  textureFile;
    sf::Texture tileSheet;
    sf::RectangleShape collisionBox;

    void clear();

    int fromX;
    int toX;
    int fromY;
    int toY;
    int layer;
};

#endif //DRAGHI_E_SOTTERRANEI_TILEMAP_H
