//
// Created by alpacox on 05/03/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_WEAPON_H
#define DRAGHI_E_SOTTERRANEI_WEAPON_H

#include "Item.h"

class Item;

class Weapon : public Item {
public:
    Weapon(unsigned value, std::string texture_file);
    virtual ~Weapon();

    virtual Item* clone() = 0;

    virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr) = 0;

protected:
    sf::Texture weapon_texture;
    sf::Sprite weapon_sprite;

    int damageMin;
    int damageMax;
    unsigned range;

private:
    void initVariables();

};

#endif //DRAGHI_E_SOTTERRANEI_WEAPON_H
