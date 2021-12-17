//
// Created by alpacox on 17/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMYFACTORY_H
#define DRAGHI_E_SOTTERRANEI_ENEMYFACTORY_H

#include "Enemy.h"

class EnemyFactory {

public:
    EnemyFactory();
    virtual ~EnemyFactory();

    Enemy* createEnemy(short type);

};


#endif //DRAGHI_E_SOTTERRANEI_ENEMYFACTORY_H
