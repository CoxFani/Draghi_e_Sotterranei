//
// Created by gabriele on 03/12/21.
//

#include "precompiler.h"
#include "EnemyStrategy.h"

EnemyStrategy::EnemyStrategy(std::vector<Enemy*>& activeEnemies, std::map<std::string, sf::Texture> &textures)
: textures(textures), activeEnemies(activeEnemies) {

}

EnemyStrategy::~EnemyStrategy() {

}

void EnemyStrategy::createEnemy(const short type, const float xPos, const float yPos) {
    switch(type){
        case EnemyTypes::MUMMY:
            this->activeEnemies.push_back(new Mummy(xPos, yPos, this->textures["MUMMY_SHEET"]));
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
