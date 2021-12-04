//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_BOW_H
#define DRAGHI_E_SOTTERRANEI_BOW_H

#include "RangedWeapon.h"

class RangedWeapon;

class Bow : public RangedWeapon {
public:
    Bow(unsigned value, std::string texture_file);
    virtual ~Bow();

    Bow* clone() override;

private:

};

#endif //DRAGHI_E_SOTTERRANEI_BOW_H
