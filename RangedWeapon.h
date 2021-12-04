//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_RANGEDWEAPON_H
#define DRAGHI_E_SOTTERRANEI_RANGEDWEAPON_H

#include "Item.h"

class Item;

class RangedWeapon : public Item {
public:
    RangedWeapon(unsigned value);
    virtual ~RangedWeapon();

    virtual RangedWeapon* clone() = 0;

private:

};


#endif //DRAGHI_E_SOTTERRANEI_RANGEDWEAPON_H
