//
// Created by alpacox on 12/03/21.
//

#include "MartialWeapon.h"

MartialWeapon::MartialWeapon(int s, bool m, bool h): Weapon(s, m, h){

}

int MartialWeapon::use(){
    int result = basicUse();
 //TODO
    return result;
}

MartialWeapon* MartialWeapon::clone() const {
    return new MartialWeapon(*this);
}

