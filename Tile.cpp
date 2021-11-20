//
// Created by alpacox on 07/10/21.
//

#include "precompiler.h"
#include "Tile.h"

Tile::Tile() {
    this->collision = false;
    this->type = 0;
}

Tile::Tile(int grid_x, int grid_y, float gridSizeF, sf::Texture& texture, const sf::IntRect& texture_rect, bool collision, short type) {

    //this->shape.setOutlineThickness(1.f);
    //this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setPosition(static_cast<float>(grid_x) * gridSizeF, static_cast<float>(grid_y) * gridSizeF);
    this->shape.setTexture(texture);
    this->shape.setTextureRect(texture_rect);
    this->collision = collision;
    this->type = type;
}

Tile::~Tile() {

}

void Tile::update() {

}

void Tile::render(sf::RenderTarget &target, sf::Shader* shader, const sf::Vector2f heroPosition) {

    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", heroPosition);

        target.draw(this->shape, shader);
    }
    else
        target.draw(this->shape);

}

const std::string Tile::getAsString() const {
    std::stringstream ss;
    ss << this->shape.getTextureRect().left << " " << this->shape.getTextureRect().top << " " << this->collision << " " << this->type;
    return ss.str();
}

const sf::Vector2f &Tile::getPosition() const {
    return this->shape.getPosition();
}

const bool & Tile::getCollision() const {
    return this->collision;
}

const bool Tile::intersects(const sf::FloatRect bounds) const{
    return  this->shape.getGlobalBounds().intersects(bounds);
}

const sf::FloatRect Tile::getGlobalBounds() const {
    return this->shape.getGlobalBounds();
}

const short &Tile::getType() const {
    return this->type;
}
