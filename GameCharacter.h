//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H
#define DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H

#include "Weapon.h"
#include "HitboxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class GameCharacter {
public:
    GameCharacter();
    virtual ~GameCharacter();

    void setTexture(sf::Texture& texture);
    void createHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
    void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimationComponent(sf::Texture& texture_sheet);

    virtual void setPosition(const float x, const float y);
    virtual void move(const float x, const float y, const float& dt);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget& target);

protected:
    sf::Sprite sprite;

    HitboxComponent* hitboxComponent;
    MovementComponent* movementComponent;
    AnimationComponent* animationComponent;

private:
    void initVariables();

/* POINTZERO
using namespace std;

class GameCharacter {
public:
    GameCharacter();
    explicit GameCharacter(int maxHP, int ac, int str, int intel, int dex);
    virtual ~GameCharacter();

    //virtual void move(); //TODO

    //virtual void fight(GameCharacter &enemy); //TODO

    bool isLegalFight(const GameCharacter &enemy, Weapon &wpn) const;

    void basicFight(GameCharacter &enemy);

    static int distance(const GameCharacter &h, const GameCharacter &e);

    int getPosX() const {
        return posX;
    }
    void setPosX(int posX) {
        GameCharacter::posX = posX;
    }
    int getPosY() const {
        return posY;
    }
    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    int getHealth() const{
        return health;
    }

    void setHealth(int hp){
        GameCharacter::health = hp;
    }

    Weapon* getWeapon(){
        return weapon;
    }
    void setWeapon(Weapon* wpn){
        GameCharacter::weapon = wpn;
    }

    int getArmorClass() const{
        return armorClass;
    }

    void setArmorClass(int ac){
        GameCharacter::armorClass = ac;
    }

    int getStrenght(){
        return strength;
    }

    void setStrength(int str){
        GameCharacter::strength = str;
    }

    int getIntelligence(){
        return intelligence;
    }

    void setIntelligence(int intel){
        GameCharacter::intelligence = intel;
    }

    int getDexterity(){
        return dexterity;
    }

    void setDexterity(int dex){
        GameCharacter::dexterity = dex;
    }

    const string toString();



protected:
    int maxHealth;
    int health;
    int armorClass;
    int intelligence;
    int strength;
    int dexterity;
    int posX;
    int posY;
    Weapon* weapon;
*/
};

#endif //DRAGHI_E_SOTTERRANEI_GAMECHARACTER_H