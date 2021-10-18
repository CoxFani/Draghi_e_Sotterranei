//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HERO_H
#define DRAGHI_E_SOTTERRANEI_HERO_H

#include "GameCharacter.h"
//#include "GameState.h"

class Hero : public GameCharacter {
public:

    Hero(float x, float y, sf::Texture& texture_sheet);
    virtual ~Hero();

    void updateAttack();
    void updateAnimation(const float& dt);
    virtual void update(const float& dt);
/*

    bool canLevelUp();
    void levelUpStats();

    int getChoice();

    int getExp();

    const string toString();
*/
private:

    bool attacking;

    void initVariables();
    void initComponents();

protected:
/*
    string name;
    int exp;
    int expNext;
    int level;
    int statsPoints;
*/
};


#endif //DRAGHI_E_SOTTERRANEI_HERO_H
