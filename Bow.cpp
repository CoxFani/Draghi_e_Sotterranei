//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "Bow.h"

Bow::Bow(unsigned value, std::string texture_file)
: RangedWeapon(value, texture_file){
}

Bow::~Bow() {

}

Bow *Bow::clone() {

    return new Bow(*this);
}
