//
// Created by alpacox on 05/03/21.
//

#include "precompiler.h"
#include "Weapon.h"
#include "Dice.h"

Weapon::Weapon(unsigned value, std::string texture_file) : Item(value) {
    this->initVariables();
    if(!this->weapon_texture.loadFromFile(texture_file))
        std::cout <<"ERROR::SWORD::COULD NOT LOAD WEAPON TEXTURE::"<< texture_file << "\n";
    this->weapon_sprite.setTexture(this->weapon_texture);
}

Weapon::~Weapon() {

}

void Weapon::initVariables() {
    this->range = 10;
}

const unsigned &Weapon::getRange() const {
    return this->range;
}
