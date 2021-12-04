//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "Item.h"

Item::Item(unsigned value) {

    this->initVariables();

    this->value = value;
    this->type = ItemTypes::ITEM_DEFAULT;
}

Item::~Item() {

}

void Item::initVariables() {

}
