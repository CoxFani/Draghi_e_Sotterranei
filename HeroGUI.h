//
// Created by alpacox on 14/11/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HEROGUI_H
#define DRAGHI_E_SOTTERRANEI_HEROGUI_H

#include "Hero.h"

class Hero;

class HeroGUI {
public:
    HeroGUI(Hero* hero);
    virtual ~HeroGUI();

    void updateHPBar();
    void update(const float& dt);

    void renderHPBar(sf::RenderTarget &target);
    void render(sf::RenderTarget& target);

private:
    Hero* hero;

    sf::Font font;
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInner;
    float hpBarMaxWidth;

    void initFont();
    void initHPBar();

};


#endif //DRAGHI_E_SOTTERRANEI_HEROGUI_H
