//
// Created by alpacox on 15/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MAGICALWEAPON_H
#define DRAGHI_E_SOTTERRANEI_MAGICALWEAPON_H

#include "MartialWeapon.h"
#include "RangedWeapon.h"


class MagicalWeapon: public MartialWeapon, public RangedWeapon { // fino a che l'arma ha il "carburante magico" si comporta come ranged e quand lo finisce si comporta come martial
public:
    explicit MagicalWeapon(int s = 10, int mf = 10, bool m  = false, bool h = false);

    virtual int use() override;
    virtual MagicalWeapon* clone() const override;





};


#endif //DRAGHI_E_SOTTERRANEI_MAGICALWEAPON_H
