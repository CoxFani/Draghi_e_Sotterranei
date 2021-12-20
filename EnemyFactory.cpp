//
// Created by gabriele on 03/12/21.
//

#include "precompiler.h"
#include "EnemyFactory.h"

EnemyFactory::EnemyFactory(std::vector<Enemy*>& activeEnemies,
                             std::map<std::string, sf::Texture> &textures, GameCharacter& hero)
: textures(textures), activeEnemies(activeEnemies), hero(hero) {

}

EnemyFactory::~EnemyFactory() {

}

void EnemyFactory::createEnemy(const short type, const float xPos, const float yPos, EnemySpawnerTile& enemy_spawner_tile) {
    switch(type){
        case EnemyTypes::MUMMY:{
            float animations[3][7] = { 11.f, 0, 0, 3, 0, 48, 48,
                                       8.f, 0, 1, 5, 1, 48, 48,
                                       12.f, 0, 3, 5, 3, 48, 48};
            activeEnemies.push_back(new Enemy(xPos, yPos, textures["MUMMY_SHEET"], enemy_spawner_tile, this->hero, animations));

            enemy_spawner_tile.increaseEnemyCounter();
            break;
        }
        default:

            std::cout << "ERROR::ENEMYSYSTEM::CREATENEMY::TYPE DOES NOT EXIST" << "\n";
            break;
    }
}

void EnemyFactory::update(const float &dt) {

}

void EnemyFactory::render(sf::RenderTarget *target) {

}

void EnemyFactory::removeEnemy(const int index) {
    activeEnemies[index]->getEnemySpawnerTile().decreaseEnemyCounter();
    //TODO ritardare la cancellazione del nemico poter inserire animzaione di morte
    delete activeEnemies[index];
    activeEnemies.erase(activeEnemies.begin() + index);
}
