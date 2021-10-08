//
// Created by alpacox on 08/10/21.
//

#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow& window) {
    this->background.setSize(sf::Vector2f(
            static_cast<float >(window.getSize().x),
            static_cast<float >(window.getSize().y)
               )
            );
    this->background.setFillColor(sf::Color(20, 20, 20, 100));

    this->container.setSize(sf::Vector2f(
            static_cast<float >(window.getSize().x) / 4.f,
            static_cast<float >(window.getSize().y - 300.f)
               )
            );
    this->container.setFillColor(sf::Color(20, 20, 20, 200));
    this->container.setPosition(
            static_cast<float >(window.getSize().x) / 2.f - this->container.getSize().x /2.f,
            150.f
            );


}

PauseMenu::~PauseMenu() {
    auto i = this->buttons.begin();
    for (i = this->buttons.begin(); i != this->buttons.end(); ++i)
    {
        delete i->second;
    }

}

void PauseMenu::update() {

}

void PauseMenu::render(sf::RenderTarget &target) {
    target.draw(background);
    target.draw(container);

    for(auto &i : this->buttons){
        i.second->render(target);
    }

}
