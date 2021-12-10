//
// Created by alpacox on 09/12/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TAB_H
#define DRAGHI_E_SOTTERRANEI_TAB_H

#include "Hero.h"
#include "Gui.h"

class Tab {
public:
    Tab(sf::VideoMode& vm, sf::Font& font, Hero& hero, bool hidden);
    virtual ~Tab();

    const bool& getHidden() const;
    const bool& getOpen() const;

    void hide();
    void show();

    virtual void update() = 0;
    virtual void render(sf::RenderTarget& target) = 0;

protected:

    sf::VideoMode& vm;
    sf::Font& font;
    Hero& hero;
    bool hidden;
};


#endif //DRAGHI_E_SOTTERRANEI_TAB_H
