//
// Created by alpacox on 07/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILE_H
#define DRAGHI_E_SOTTERRANEI_TILE_H

enum TileTypes {DEFAULT = 0, DAMAGING}; //solo esempio, da completare in seguito

class Tile {
public:
    Tile();
    Tile(int grid_x, int grid_y, float gridSizeF, sf::Texture& texture, const sf::IntRect& texture_rect, bool collision = false, short type = TileTypes::DEFAULT);
    virtual ~Tile();

    const std::string getAsString() const;
    void update();
    void render(sf::RenderTarget& target);
    const sf::Vector2f& getPosition() const;
    const bool &getCollision() const;
    const bool intersects(const sf::FloatRect bounds) const;
    const sf::FloatRect getGlobalBounds() const;

protected:
    sf::RectangleShape shape;
    short type;
    bool collision;

private:


};

#endif //DRAGHI_E_SOTTERRANEI_TILE_H
