//
// Created by alpacox on 05/03/21.
//

#include "Dice.h"

#include <ctime>
#include <cstdlib>

Dice::Dice(int f): faces(f){
    srand(time(0));
}

int Dice::roll(int r){

    int result = 0;

    for (int i = 0; i < r ; i++)
        result += rand() % faces + 1;
    return result;
}