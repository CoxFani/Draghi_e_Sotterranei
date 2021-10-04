//
// Created by alpacox on 01/10/21.
//

#ifndef DRAGHI_E_SOTTERRANEI_MOVEMENTCOMPONENT_H
#define DRAGHI_E_SOTTERRANEI_MOVEMENTCOMPONENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum movement_states{ IDLE = 0, MOVING,  MOVING_RIGHT, MOVING_LEFT, MOVING_UP, MOVING_DOWN };

class MovementComponent {

public:
    MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    ~MovementComponent();

    const sf::Vector2f& getVelocity() const;

    const bool getState(const short unsigned state) const;




    void move(const float x, const float y, const float& dt);
    void update(const float& dt);

private:
    sf::Sprite& sprite;

    float  maxVelocity;
    float accelleration;
    float deceleration;

    sf::Vector2f velocity;


};


#endif //DRAGHI_E_SOTTERRANEI_MOVEMENTCOMPONENT_H
