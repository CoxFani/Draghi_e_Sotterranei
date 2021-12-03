//
// Created by gabriele on 03/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMYSTRATEGY_H
#define DRAGHI_E_SOTTERRANEI_ENEMYSTRATEGY_H

#include "EnemySpawnerTile.h"
#include "Mummy.h"

enum EnemyTypes {MUMMY = 0};

class EnemyStrategy {
public:
    EnemyStrategy(std::vector<Enemy*>& activeEnemies, std::map<std::string, sf::Texture>& textures);
    virtual ~EnemyStrategy();

    void createEnemy(const short type, const float xPos, const float yPos);
    void update(const float& dt);
    void render(sf::RenderTarget* target);

private:
    std::map<std::string, sf::Texture>& textures;
    std::vector<Enemy*>& activeEnemies;

};


#endif //DRAGHI_E_SOTTERRANEI_ENEMYSTRATEGY_H
