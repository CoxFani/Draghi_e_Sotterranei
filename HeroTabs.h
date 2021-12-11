//
// Created by alpacox on 09/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_HEROTABS_H
#define DRAGHI_E_SOTTERRANEI_HEROTABS_H

#include "CharacterTab.h"


class HeroTabs {
public:
    HeroTabs(sf::VideoMode& vm,sf::Font& font, Hero& hero);
    virtual ~HeroTabs();

    const bool getKeyTime();
    const bool tabsOpen();

    void toggleCharacterTab();

    void update();
    void render(sf::RenderTarget& target);


private:

    CharacterTab characterTab;

    sf::VideoMode& vm;
    sf::Font& font;
    Hero& hero;
    sf::Clock keyTimer;
    float keyTimeMax;

    void initKeyTime();

};


#endif //DRAGHI_E_SOTTERRANEI_HEROTABS_H
