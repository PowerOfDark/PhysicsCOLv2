//
// Created by starwader on 8/16/17.
//

#ifndef PONGSFML_CIRCLE_H
#define PONGSFML_CIRCLE_H

#include <SFML/Graphics.hpp>
#include <utility>

class Circle {
public:
    sf::CircleShape circleShape;
    float circleMass;
    float vx = 0, vy = 0;

    explicit Circle(const sf::CircleShape &circleShape) {
        this->circleShape = circleShape;
        this->circleMass = 100;
    }

    Circle(const sf::CircleShape &circleShape, float mass) {
        this->circleShape = circleShape;
        this->circleMass = mass;
    }

    Circle(const sf::CircleShape &circleShape, float mass, float vx, float vy) {
        this->circleShape = circleShape;
        this->circleMass = mass;
        this->vx = vx;
        this->vy = vy;
    }
};


#endif //PONGSFML_CIRCLE_H
