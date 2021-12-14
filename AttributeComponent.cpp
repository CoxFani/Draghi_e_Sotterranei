//
// Created by gabriele on 13/11/21.
//

#include "precompiler.h"
#include "AttributeComponent.h"

AttributeComponent::AttributeComponent(int level) {
    this->level = level;
    exp = 0;
    expNext = static_cast<int>((50 * pow(this->level, 3) - 150 * pow(this->level, 2) + 400 * this->level) / 3);
    attributePoints = 2;
    strength = 1;
    vitality = 1;
    dexterity = 1;
    agility = 1;
    intelligence = 1;

    updateLevel();
    updateStats(true);
}

AttributeComponent::~AttributeComponent() {

}

void AttributeComponent::updateStats(const bool reset) {
    //TODO modificare equazioni di aumento caratteristiche
    hpMax = vitality * 5 + vitality + strength / 2 + intelligence / 5;
    damageMin = strength * 2 + strength / 4 + intelligence / 5;
    damageMax = strength * 2 + strength / 2 + intelligence / 5;
    accuracy = dexterity * 5 + dexterity / 2 + intelligence / 5;
    defence = agility * 2 + agility / 4 + intelligence / 5;
    luck = intelligence * 2 + intelligence / 5;

    if(reset)
        hp = hpMax;
}

void AttributeComponent::updateLevel() {
    while(exp >= expNext){
        ++level;
        exp -= expNext;
        expNext = static_cast<int>((50 * pow(level, 3) - 150 * pow(level, 2) + 400 * level) / 3);
        ++attributePoints;
    }
}

void AttributeComponent::update() {
    updateLevel();
}

std::string AttributeComponent::debugPrint() const {
    std::stringstream ss;
    ss << "Level: " << level << "\n"
       << "Exp: " << exp << "\n"
       << "Exp Next: " << expNext << "\n"
       << "Attp: " << attributePoints << "\n";
    return ss.str();
}

void AttributeComponent::loseHP(const int hp) {
    this->hp -= hp;

    if(this->hp < 0)
        this->hp = 0;
}

void AttributeComponent::gainHP(const int hp) {
    this->hp += hp;

    if(this->hp > this->hpMax)
        this->hp = this->hpMax;
}

void AttributeComponent::loseEXP(const int exp) {
    this->exp -= exp;

    if(this->exp < 0)
        this->exp = 0;
}

void AttributeComponent::gainEXP(const int exp) {
    this->exp += exp;
    updateLevel();
}

const bool AttributeComponent::isDead() const {
    return hp <= 0;
}
