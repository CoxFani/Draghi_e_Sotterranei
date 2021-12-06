//
// Created by gabriele on 13/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H


class AttributeComponent {

public:
    AttributeComponent(int level);
    virtual ~AttributeComponent();

    int level;
    int exp;
    int expNext;
    int attributePoints;
    int strength;
    int vitality;
    int dexterity;
    int agility;
    int intelligence;

    int hp;
    int hpMax;
    int damageMin;
    int damageMax;
    int accuracy;
    int defence;
    int luck;

    void updateStats(const bool reset);
    void updateLevel();
    void update();

    void loseHP(const int hp);
    void gainHP(const int hp);
    void loseEXP(const int exp);
    void gainEXP(const int exp);

    std::string debugPrint() const;

    const bool isDead() const;
};


#endif //DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H