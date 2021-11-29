//
// Created by alpacox on 07/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_TILE_H
#define DRAGHI_E_SOTTERRANEI_TILE_H

enum TileTypes {DEFAULT = 0, DAMAGING, FLAVOUR, ENEMYSPAWNER}; //solo esempio, da completare in seguito

class Tile {
public:
    Tile();
    Tile(int grid_x, int grid_y, float gridSizeF, const sf::Texture& texture, const sf::IntRect& texture_rect, bool collision = false, short type = TileTypes::DEFAULT);
    virtual ~Tile();

    const short& getType() const;

    const bool & getCollision() const;
    const sf::Vector2f& getPosition() const;
    const sf::FloatRect getGlobalBounds() const;
    const bool intersects(const sf::FloatRect bounds) const;
    const std::string getAsString() const;
    virtual void update();
    virtual void render(sf::RenderTarget& target, sf::Shader* shader = nullptr, const sf::Vector2f hero_position = sf::Vector2f());

protected:
    sf::Sprite shape;
    short type;
    bool collision;

private:


};

#endif //DRAGHI_E_SOTTERRANEI_TILE_H
