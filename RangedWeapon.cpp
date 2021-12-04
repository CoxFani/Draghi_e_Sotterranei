//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(unsigned value, std::string texture_file) : Weapon(value, texture_file) {
    this->type = ItemTypes::ITEM_RANGEDWEAPON;
}

RangedWeapon::~RangedWeapon() {

}
