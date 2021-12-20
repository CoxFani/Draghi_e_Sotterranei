//
// Created by alpacox on 25/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILEMAP_H
#define DRAGHI_E_SOTTERRANEI_TILEMAP_H

#include "EnemySpawnerTile.h"
#include "RegularTile.h"
#include "EnemyFactory.h"

class Tile;
class GameCharacter;
class EnemySpawnerTile;

class TileMap {
public:

    TileMap(float gridSize, int  width, int  height, std::string texture_file);
    TileMap(const std::string file_name);
    virtual ~TileMap();

    const bool tileEmpty(const int x, const int y, const int z) const;
    const sf::Texture* getTileSheet() const;
    const int getLayerSize(const int x, const int y, const int layer) const;
    const sf::Vector2i& getMaxSizeGrid() const;
    const sf::Vector2f& getMaxSizeF() const;

    void addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
    void addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect,
                 const int enemy_type, const int enemy_amount, const int enemy_tts, const int enemy_md);

    void removeTile(const int x, const int y, const int z, const int type = -1);
    void saveToFile(const std::string file_name);
    void loadFromFile(const std::string file_name);
    const bool checkType(const int x, const int y, const int z, const int type) const;

    void updateWorldBoundsCollision(GameCharacter* gameCharacter, const float& dt);
    void updateTileCollision(GameCharacter* gameCharacter, const float& dt);
    void updateTiles(GameCharacter* gameCharacter, const float& dt, EnemyFactory& enemyStrategy);
    void update(GameCharacter* gameCharacter, const float& dt);
    void render(
            sf::RenderTarget& target,
            const sf::Vector2i& gridPosition,
            sf::Shader* shader = nullptr,
            const sf::Vector2f heroPosition = sf::Vector2f(),
            const bool show_collision = false
                    );
    void renderDeferred(sf::RenderTarget& target, sf::Shader* shader = nullptr, const sf::Vector2f heroPosition = sf::Vector2f());

private:
    float gridSizeF;
    int gridSizeI;
    sf::Vector2i maxSizeWorldGrid;
    sf::Vector2f maxSizeWorldF;
    int layers;
    std::vector< std::vector< std::vector< std::vector< Tile*> > > > map;
    std::stack<Tile*> deferredRenderStack;
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
