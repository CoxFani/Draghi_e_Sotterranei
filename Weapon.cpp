//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Weapon.h"
#include "Dice.h"

Weapon::Weapon(unsigned level, unsigned value, std::string texture_file)
: Item(level, value) {

    this->initVariables();

    if(!this->weapon_texture.loadFromFile(texture_file))
        std::cout <<"ERROR::SWORD::COULD NOT LOAD WEAPON TEXTURE::"<< texture_file << "\n";
    this->weapon_sprite.setTexture(this->weapon_texture);
}

Weapon::Weapon(unsigned level, unsigned int damageMin, unsigned int damageMax, unsigned int range,
               unsigned int value,
               std::string texture_file)
               : Item(level, value){

    this->initVariables();

    this->damageMin = damageMin;
    this->damageMax = damageMax;
    this->range = range;

    if(!this->weapon_texture.loadFromFile(texture_file))
        std::cout <<"ERROR::SWORD::COULD NOT LOAD WEAPON TEXTURE::"<< texture_file << "\n";
    this->weapon_sprite.setTexture(this->weapon_texture);

}

Weapon::~Weapon() {

}

void Weapon::initVariables() {
    this->range = 65;
    this->damageMin = 1;
    this->damageMax = 2;

    this->attackTimer.restart();
    this->attackTimerMax = 500;
}

const unsigned &Weapon::getDamageMin() const {
    return this->damageMin;
}

const unsigned &Weapon::getDamageMax() const {
    return this->damageMax;
}

const unsigned Weapon::getDamage() const{
    return rand() % (this->damageMax - this->damageMin + 1) + (this->damageMin);
}

const unsigned &Weapon::getRange() const {
    return this->range;
}

const bool Weapon::getAttackTimer() {
    if(this->attackTimer.getElapsedTime().asMilliseconds() >= this->attackTimerMax){
        this->attackTimer.restart();
        return true;
    }
    return false;
}




