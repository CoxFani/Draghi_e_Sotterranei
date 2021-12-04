//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ITEM_H
#define DRAGHI_E_SOTTERRANEI_ITEM_H

enum ItemTypes {ITEM_DEFAULT = 0, ITEM_RANGEDWEAPON, ITEM_MELEEWEAPON};
enum ItemRarities {COMMON = 0, UNCOMMON, RARE, EPIC, LEGENDARY, ARTIFACT};

class Item {
public:
    Item(unsigned value);
    virtual ~Item();

    virtual Item* clone() = 0;

protected:
    short unsigned type;
    unsigned value;

private:
    void initVariables();

};


#endif //DRAGHI_E_SOTTERRANEI_ITEM_H
