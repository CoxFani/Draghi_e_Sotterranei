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

    void updateEXPBar();
    void updateHPBar();
    void update(const float& dt);

    void renderEXPBar(sf::RenderTarget &target);
    void renderHPBar(sf::RenderTarget &target);
    void render(sf::RenderTarget& target);

private:
    Hero* hero;

    sf::Font font;

    std::string expBarString;
    sf::Text expBarText;
    float expBarMaxWidth;
    sf::RectangleShape expBarBack;
    sf::RectangleShape expBarInner;

    std::string hpBarString;
    sf::Text hpBarText;
    float hpBarMaxWidth;
    sf::RectangleShape hpBarBack;
    sf::RectangleShape hpBarInner;

    void initFont();
    void initHPBar();
    void initEXPBar();

};


#endif //DRAGHI_E_SOTTERRANEI_HEROGUI_H
