//
// Created by gabriele on 25/11/21.
//

#include "precompiler.h"
#include "Bow.h"

Bow::Bow(unsigned value)
: RangedWeapon(value){
}

Bow::~Bow() {

}

Bow *Bow::clone() {

    return new Bow(*this);
}
