//
// Created by gabriele on 03/12/21.
//

#include "precompiler.h"
#include "RegularTile.h"

RegularTile::RegularTile(short type, int grid_x, int grid_y, float gridSizeF,
                         const sf::Texture& texture, const sf::IntRect& texture_rect,
                         bool collision)
                         : Tile (type, grid_x, grid_y, gridSizeF, texture, texture_rect, collision){

}

RegularTile::~RegularTile() {

}

void RegularTile::update() {

}

void RegularTile::render(sf::RenderTarget &target, sf::Shader *shader, const sf::Vector2f hero_position) {
    if(shader){
        shader->setUniform("hasTexture", true);
        shader->setUniform("lightPos", hero_position);

        target.draw(this->shape, shader);
    }
    else
        target.draw(this->shape);
}
