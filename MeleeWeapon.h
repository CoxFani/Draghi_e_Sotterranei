//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H
#define DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H

#include "Item.h"

class Item;

class MeleeWeapon : public Item {
public:
    MeleeWeapon();
    virtual ~MeleeWeapon();

    virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader) = 0;

private:

protected:
    sf::Texture weapon_texture;
    sf::Sprite weapon_sprite;

    int damageMin;
    int damageMax;

};


#endif //DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H
