//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned level, unsigned damageMin, unsigned damageMax, unsigned range,
                         unsigned value,
                         std::string texture_file)
: Weapon(level, damageMin, damageMax, range, value, texture_file) {
    this->type = ItemTypes::ITEM_MELEEWEAPON;
}

MeleeWeapon::~MeleeWeapon() {

}

void MeleeWeapon::generate(const unsigned int levelMin, const unsigned int levelMax) {

    this->level = rand() % (levelMax - levelMin + 1) + levelMin;

    this->damageMin = this->level * (rand() % 2 + 1);
    this->damageMax = this->level * (rand() % 2 + 1) + this->damageMin;

    this->range = this->level + rand() % 10 + 50;

    this->value = this->level + this->damageMin + damageMax + this->range + (rand() % level * 10);

    std::cout << this->level << " " << this->damageMin << " " << this->damageMax << " " << this->range << " " << this->value << "\n";
}
