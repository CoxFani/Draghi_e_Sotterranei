//
// Created by gabriele on 13/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H


class AttributeComponent {

public:
    AttributeComponent();
    virtual ~AttributeComponent();

    unsigned level;
    unsigned exp;
    unsigned expNext;
    unsigned attributePoints;
    unsigned strength;
    unsigned vitality;
    unsigned dexterity;
    unsigned agility;
    unsigned intelligence;

};


#endif //DRAGHI_E_SOTTERRANEI_ATTRIBUTECOMPONENT_H