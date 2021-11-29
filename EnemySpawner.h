//
// Created by alpacox on 29/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMYSPAWNER_H
#define DRAGHI_E_SOTTERRANEI_ENEMYSPAWNER_H

#include "Tile.h"

class EnemySpawner:
        public Tile {
public:
    EnemySpawner(int grid_x, int grid_y, float gridSizeF,
                 const sf::Texture& texture, const sf::IntRect& texture_rect,
                 float grid_size, int enemy_type, int enemy_amount, int enemy_time_to_spawn, float enemy_max_distance);
    virtual ~EnemySpawner();


    void update() override;
    void render(sf::RenderTarget &target, sf::Shader* shader = nullptr, const sf::Vector2f hero_position = sf::Vector2f()) override;

private:

    float gridSize;
    int enemyType;
    int enemyAmount;
    int enemyTimeToSpawn;
    float enemyMaxDistance;


};


#endif //DRAGHI_E_SOTTERRANEI_ENEMYSPAWNER_H
