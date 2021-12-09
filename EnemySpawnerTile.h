//
// Created by alpacox on 29/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMYSPAWNERTILE_H
#define DRAGHI_E_SOTTERRANEI_ENEMYSPAWNERTILE_H

#include "Tile.h"

class EnemySpawnerTile:
        public Tile {
public:
    EnemySpawnerTile(int grid_x, int grid_y, float gridSizeF,
                     const sf::Texture& texture, const sf::IntRect& texture_rect,
                     int enemy_type, int enemy_amount, int enemy_time_to_spawn, float enemy_max_distance);
    virtual ~EnemySpawnerTile();

    virtual const std::string getAsString() const override;
    const bool& getSpawned() const;
    const int& getEnemyCounter() const;

    void setSpawn(const bool spawned);

    const bool canSpawn(); //da definire
    void increaseEnemyCounter();
    void decreaseEnemyCounter();


    void update() override;
    void render(sf::RenderTarget &target, sf::Shader* shader = nullptr, const sf::Vector2f hero_position = sf::Vector2f()) override;

private:
    float gridSize;
    int enemyType;
    int enemyAmount;
    int enemyCounter;
    int enemyTimeToSpawn;
    float enemyMaxDistance;
    bool spawned;


};


#endif //DRAGHI_E_SOTTERRANEI_ENEMYSPAWNERTILE_H
