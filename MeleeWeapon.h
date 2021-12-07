//
// Created by gabriele on 25/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H
#define DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H

#include "Weapon.h"

class MeleeWeapon : public Weapon {
public:
    MeleeWeapon(unsigned level, unsigned damageMin, unsigned damageMax, unsigned range,
                unsigned value,
                std::string texture_file);
    virtual ~MeleeWeapon();

    virtual MeleeWeapon* clone() = 0;
    virtual void generate(const unsigned levelMin, const unsigned levelMax) override;


    virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center) = 0;
    virtual void render(sf::RenderTarget& target, sf::Shader* shader) = 0;
};


#endif //DRAGHI_E_SOTTERRANEI_MELEEWEAPON_H
