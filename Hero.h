//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H

#include <cmath>
#include <sstream>
#include "GameCharacter.h"
#include "GameState.h"

class Hero : public GameCharacter {
public:

    Hero(string n, int maxHP, int ac, int str, int intel, int dex);

    bool canLevelUp();
    void levelUpStats();

    int getChoice();

    int getExp();

    const string toString();



protected:

    string name;
    int exp;
    int expNext;
    int level;
    int statsPoints;

};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
