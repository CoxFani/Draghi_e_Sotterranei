//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Enemy.h"

Enemy::Enemy() {
    this->initVariables();
    this->initAnimations();
}

Enemy::~Enemy() {

}

void Enemy::loseHP(const int hp) {
    if(this->attributeComponent) {
        this->attributeComponent->loseHP(hp);
    }
}

const AttributeComponent *Enemy::getAttributeComp() const {
    if(this->attributeComponent)
        return this->attributeComponent;
    else {
        std::cout << "ERROR::ENEMY::ATTRIBUTECOMPONENT IS NOT INIZIALIZES" << "\n";
        return nullptr;
    }
}

const bool Enemy::isDead() const {
    if(this->attributeComponent){
        return this->attributeComponent->isDead();
    }
    return false;
}

void Enemy::initVariables() {
    this->gainExp = 10;
}

void Enemy::initAnimations() {

}

const unsigned &Enemy::getGainExp() const {
    return this->gainExp;
}
