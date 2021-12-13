//
// Created by gabriele on 03/12/21.
//

#include "precompiler.h"
#include "EnemyStrategy.h"

EnemyStrategy::EnemyStrategy(std::vector<Enemy*>& activeEnemies,
                             std::map<std::string, sf::Texture> &textures, GameCharacter& hero)
: textures(textures), activeEnemies(activeEnemies), hero(hero) {

}

EnemyStrategy::~EnemyStrategy() {

}

void EnemyStrategy::createEnemy(const short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile) {
    switch(type){
        case EnemyTypes::MUMMY:
            this->activeEnemies.push_back(new Mummy(xPos, yPos, this->textures["MUMMY_SHEET"], enemy_spawner_tile, this->hero));
            enemy_spawner_tile.increaseEnemyCounter();
            break;
        default:
            std::cout << "ERROR::ENEMYSYSTEM::CREATENEMY::TYPE DOES NOT EXIST" << "\n";
            break;
    }
}

void EnemyStrategy::update(const float &dt) {

}

void EnemyStrategy::render(sf::RenderTarget *target) {

}

void EnemyStrategy::removeEnemy(const int index) {
    this->activeEnemies[index]->getEnemySpawnerTile().decreaseEnemyCounter();
    //TODO ritardare la cancellazione del nemico poter inserire animzaione di morte
    delete this->activeEnemies[index];
    this->activeEnemies.erase(this->activeEnemies.begin() + index);
}
