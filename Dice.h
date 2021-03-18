//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_DICE_H
#define DRAGHI_E_SOTTERRANEI_DICE_H


class Dice {
public:
    Dice(int f);

    int roll(int r);

private:
    int faces;
    static int numRolls;
    const int maxRolls = 1000;
};


#endif //DRAGHI_E_SOTTERRANEI_DICE_H
