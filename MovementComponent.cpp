//
// Created by alpacox on 01/10/21.
//

#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration)
: sprite(sprite), maxVelocity(maxVelocity), accelleration(acceleration), deceleration(deceleration){


}

MovementComponent::~MovementComponent() {

}

void MovementComponent::update(const float &dt) {

    if(this->velocity.x > 0.f) {
        if(this->velocity.x > this->maxVelocity)
            this->velocity.x = this->maxVelocity;

        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;

    }
    else if(this->velocity.x < 0.f){
        if (this->velocity.x < -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;

        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }




    if(this->velocity.y > 0.f) {
        if(this->velocity.y > this->maxVelocity)
            this->velocity.y = this->maxVelocity;

        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f)
            this->velocity.y = 0.f;

    }
    else if(this->velocity.y < 0.f){
        if (this->velocity.y < -this->maxVelocity)
            this->velocity.y = -this->maxVelocity;

        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }



    this->sprite.move(this->velocity * dt);


}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt) {

    this->velocity.x += this->accelleration * dir_x;

    this->velocity.y += this->accelleration * dir_y;

}

const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->velocity;
}


const bool MovementComponent::getState(const unsigned short state) const {
    switch (state){

        case IDLE:
            if(this->velocity.x == 0.f && this->velocity.y == 0.f)
                return true;
            break;

        case MOVING:
            if(this->velocity.x != 0.f && this->velocity.y != 0.f)
                return true;
            break;

        case MOVING_RIGHT:
            if(this->velocity.x > 0.f)
                return true;
            break;

        case MOVING_LEFT:
            if(this->velocity.x < 0.f)
                return true;
            break;

        case MOVING_UP:
            if(this->velocity.y < 0.f)
                return true;
            break;

        case MOVING_DOWN:
            if(this->velocity.y > 0.f)
                return true;
            break;

    }

    return false;
}
