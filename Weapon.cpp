//
// Created by alpacox on 05/03/21.
//

#include "Weapon.h"
#include "Dice.h"

Weapon::Weapon(int s, bool m, bool h) : strength(s), magic(m), heavy(h) {
}

Weapon::Weapon() : Weapon(10,false, false) {
}

int Weapon::basicUse() {
    Dice dw(strength);
    int result = dw.roll(1);
    if (magic)
        result += 1;
    return result;
}