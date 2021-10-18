//
// Created by alpacox on 07/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILE_H
#define DRAGHI_E_SOTTERRANEI_TILE_H


class Tile {
public:
    Tile();
    Tile(float x, float y, float gridSizeF, sf::Texture& texture);
    virtual ~Tile();

    void update();
    void render(sf::RenderTarget& target);

protected:
    sf::RectangleShape shape;

private:


};

#endif //DRAGHI_E_SOTTERRANEI_TILE_H
