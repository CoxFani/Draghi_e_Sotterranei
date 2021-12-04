//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned value, std::string texture_file) : Weapon(value, texture_file) {
    this->type = ItemTypes::ITEM_MELEEWEAPON;
}

MeleeWeapon::~MeleeWeapon() {

}
