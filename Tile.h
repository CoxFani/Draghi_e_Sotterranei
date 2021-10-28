//
// Created by alpacox on 07/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILE_H
#define DRAGHI_E_SOTTERRANEI_TILE_H

enum TileTypes {DEFAULT = 0, OTHER = 1, ALTRA = 2}; //solo esempio, da completare in seguito

class Tile {
public:
    Tile();
    Tile(unsigned grid_x, unsigned grid_y, float gridSizeF, sf::Texture& texture, const sf::IntRect& texture_rect, bool collision = false, short type = TileTypes::DEFAULT);
    virtual ~Tile();

    const bool & getCollision() const;
    const sf::Vector2f& getPosition() const;
    const std::string getAsString() const;
    void update();
    void render(sf::RenderTarget& target);

protected:
    sf::RectangleShape shape;
    short type;
    bool collision;

private:


};

#endif //DRAGHI_E_SOTTERRANEI_TILE_H
