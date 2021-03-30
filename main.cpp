#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Dice.h"
#include "Map.h"
#include "TileMap.h"

int main() {

    Game game;

    while (!game.getQuit()){

        game.update();
    }
    system("PAUSE");
    return 0;
}

/* int value=0;
   Dice d20(20);
   for(int i= 0; i<50; i++) {          <- ||PROVA DADO||
       value = d20.roll(1);
       std::cout<< value << std::endl;
   }
*/
//....................................................................................................................
/*
  unsigned int windowHeight = 400;
    unsigned int windowWidth = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Draghi & Sotterranei");

    //sf::Texture texture;
    //if (!texture.loadFromFile("Images/Sprites_1.png")){              <- ||PROVA SFML||
    //    return 0;
    //}
    //sf::Sprite sprite;
    //sprite.setTexture(texture);

    Map map = Map();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for ( int i = 0; i < map.gridLength; i++){
            for ( int j = 0; j < map.gridLength; j++){
                window.draw(map.tiles[i][j]->sprite);
            }
        }

        window.display();
    }
*/