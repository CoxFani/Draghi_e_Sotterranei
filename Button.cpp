//
// Created by alpacox on 28/09/21.
//

#include "Button.h"

Button::Button(float x, float y, float width, float hight, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor){

    this->buttonState = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, hight));

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(20);
    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width/ 2) - this->text.getGlobalBounds().width / 2,
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height/ 2) - this->text.getGlobalBounds().height / 2
            );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

}

Button::~Button() {

}


void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePos) {
    /*Update the booleans for hover and pressed */

    //Idle
    this-> buttonState = BTN_IDLE;

    if (this->shape.getGlobalBounds().contains(mousePos)){
        //Hover
        this->buttonState = BTN_HOVER;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //Active
            this->buttonState = BTN_ACTIVE;
        }
    }

    switch (this->buttonState){
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;

        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;

        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            break;

        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }

}

const bool Button::isPressed() const {

    if(this->buttonState == BTN_ACTIVE)
        return true;

    return false;

}
