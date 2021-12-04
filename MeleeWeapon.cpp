//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(unsigned value)
: Item(value){

    this->type = ItemTypes::ITEM_MELEEWEAPON;

}

MeleeWeapon::~MeleeWeapon() {

}
