//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Enemy.h"

Enemy::Enemy(EnemySpawnerTile& enemy_spawner_tile) : enemySpawnerTile(enemy_spawner_tile) {
    this->initVariables();
    this->initAnimations();
}

Enemy::~Enemy() {

}

void Enemy::initVariables() {
    gainExp = 10;
    damageTimerMax = 1000;
    despawnTimerMax = 1000;
}

void Enemy::initAnimations() {

}

const unsigned &Enemy::getGainExp() const {

    return gainExp;
}

EnemySpawnerTile &Enemy::getEnemySpawnerTile() {
    return enemySpawnerTile;
}

const bool Enemy::getDamageTimerDone() const{

    return damageTimer.getElapsedTime().asMilliseconds() >= damageTimerMax;
}

const bool Enemy::getDespawnTimerDone() const{

    return despawnTimer.getElapsedTime().asMilliseconds() >= despawnTimerMax;
}

void Enemy::resetDamageTimer() {

    damageTimer.restart();
}

void Enemy::generateAttributes(const unsigned int &level) {

    gainExp = level * (rand() % 5 +1);
}

void Enemy::loseHP(const int hp) {
    if(attributeComponent) {
        attributeComponent->loseHP(hp);
    }
}

const AttributeComponent *Enemy::getAttributeComp() const {
    if(attributeComponent)
        return attributeComponent;
    else {
        std::cout << "ERROR::ENEMY::ATTRIBUTECOMPONENT IS NOT INIZIALIZES" << "\n";
        return nullptr;
    }
}

const bool Enemy::isDead() const {
    if(attributeComponent){
        return attributeComponent->isDead();
    }
    return false;
}

void Enemy::update(const float &dt, sf::Vector2f &mouse_pos_view, const sf::View& view) {

    if(vectorDistance(getPosition(), view. getCenter()) < 1500.f)
        despawnTimer.restart();
}

