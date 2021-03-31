//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H


#include "GameCharacter.h"

class Hero : public GameCharacter {
public:

    Hero();

    void levelUp();

    int getKill();



protected:

    int killCount;
    int level;

};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
