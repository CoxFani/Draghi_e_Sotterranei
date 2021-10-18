//
// Created by alpacox on 07/10/21.
//

#include "precompiler.h"
#include "Tile.h"

Tile::Tile() {

}

Tile::Tile(float x, float y, float gridSizeF, sf::Texture& texture) {

    this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
    this->shape.setFillColor(sf::Color::White);
    //this->shape.setOutlineThickness(1.f);
    //this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setPosition(x, y);
    this->shape.setTexture(&texture);
}

Tile::~Tile() {

}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &target) {

    target.draw(this->shape);
}


