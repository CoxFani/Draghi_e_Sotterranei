//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "RangedWeapon.h"

RangedWeapon::RangedWeapon(unsigned value)
: Item(value){

    this->type = ItemTypes::ITEM_RANGEDWEAPON;
}

RangedWeapon::~RangedWeapon() {

}
