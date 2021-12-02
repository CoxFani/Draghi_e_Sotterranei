//
// Created by alpacox on 29/11/21.
//
#include "precompiler.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(int grid_x, int grid_y, float gridSizeF,
                           const sf::Texture& texture, const sf::IntRect& texture_rect,
                           int enemy_type, int enemy_amount, int enemy_time_to_spawn, float enemy_max_distance)
                           : Tile(TileTypes::ENEMYSPAWNER, grid_x, grid_y, gridSizeF, texture, texture_rect, false){

    this->enemyType = enemy_type;
    this->enemyAmount = enemy_amount;
    this->enemyTimeToSpawn = enemy_time_to_spawn;
    this->enemyMaxDistance = enemy_max_distance;

}

EnemySpawner::~EnemySpawner() {

}

const std::string EnemySpawner::getAsString() const {

    std::stringstream ss;

    /**
     * x, y, z (tilemap save)
     * type
     * rect_x, rect_y,
     * enemy type
     * enemy amount
     * enemy time to spawn
     * enemy max distance
     */

    ss << this->type << " " << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top
       << this->enemyType << this->enemyAmount << this->enemyTimeToSpawn << this->enemyMaxDistance;
    return ss.str();
}

void EnemySpawner::update() {

}

void EnemySpawner::render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f hero_position) {

    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", hero_position);

        target.draw(this->shape, shader);
    }
    else
        target.draw(this->shape);}




