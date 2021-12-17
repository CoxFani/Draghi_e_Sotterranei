//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_ENEMY_H
#define DRAGHI_E_SOTTERRANEI_ENEMY_H

#include "GameCharacter.h"
#include "EnemySpawnerTile.h"

enum EnemyTypes{MUMMY = 0, SCORPION, VULTURE, HYENA, SNAKE, DECEASED, BIG_BLOATED, CENTIPEDE, BATTLE_TURTLE};


class Enemy : public GameCharacter {
public:
    Enemy(EnemySpawnerTile& enemy_spawner_tile);
    virtual ~Enemy();

    const unsigned& getGainExp() const;
    EnemySpawnerTile& getEnemySpawnerTile();
    const bool getDamageTimerDone() const;
    const bool getDespawnTimerDone() const;

    void resetDamageTimer();

    virtual void generateAttributes(const unsigned& level);

    virtual void loseHP(const int hp);
    virtual const bool isDead() const;

    virtual const AttributeComponent* getAttributeComp() const;

    virtual void updateAnimation(const float& dt) = 0;
    virtual void update(const float &dt, sf::Vector2f& mouse_pos_view, const sf::View& view);
    virtual void render(sf::RenderTarget &target, sf::Shader* shader = nullptr, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false) = 0;

protected:
    EnemySpawnerTile& enemySpawnerTile;
    unsigned gainExp;
    sf::Clock damageTimer;
    sf::Int32 damageTimerMax;
    sf::Clock despawnTimer;
    sf::Int32 despawnTimerMax;

    virtual void initVariables() = 0; //da tenere puramente virtuale?
    virtual void initAnimations() = 0; //da tenere puramente virtuale?

};


#endif //DRAGHI_E_SOTTERRANEI_ENEMY_H
