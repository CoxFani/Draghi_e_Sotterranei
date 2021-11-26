//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_SWORD_H
#define DRAGHI_E_SOTTERRANEI_SWORD_H

#include "MeleeWeapon.h"

class MeleeWeapon;

class Sword : public MeleeWeapon {
public:
    Sword();
    virtual ~Sword();

    virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center);
    virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr);

private:

};


#endif //DRAGHI_E_SOTTERRANEI_SWORD_H
