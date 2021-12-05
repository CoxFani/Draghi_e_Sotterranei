//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Enemy.h"

Enemy::Enemy() {

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



