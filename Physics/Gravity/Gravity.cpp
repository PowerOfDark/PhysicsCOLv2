//
// Created by starwader on 8/16/17.
//


#include "Gravity.h"
#include "../../Math/Math.h"

void Gravity::Attract(Circle &c1, Circle &c2) {
    sf::Vector2f vec;
    vec.x = 0.f;
    vec.y = 0.f;
    sf::Vector2f vectmp;
    vectmp.x = 0.f;
    vectmp.y = 0.f;
    //zac - c1
    sf::CircleShape &c1cs = c1.circleShape;
    sf::CircleShape &c2cs = c2.circleShape;

    vectmp.x = c2cs.getPosition().x + c2cs.getRadius() - c1.circleShape.getPosition().x - c1cs.getRadius();
    vectmp.y = c2cs.getPosition().y + c2cs.getRadius() - c1.circleShape.getPosition().y - c1cs.getRadius();
    float pythDistance = Math::Pythagoras(vectmp.x, vectmp.y);
    float G = 0.3;
    float vecValue = (c1.circleMass * c2.circleMass * G) / (pythDistance * pythDistance);
    float k = vecValue / pythDistance;

    vec.x = k * vectmp.x;
    vec.y = k * vectmp.y;
    c1.vx += vec.x;
    c1.vy += vec.y;

    //zac - c2;

    vec.x = -k * vectmp.x;
    vec.y = -k * vectmp.y;
    c2.vx += vec.x;
    c2.vy += vec.y;
}

void Gravity::Reject(sf::Vector2f &vector2f, Circle &circle) {
    sf::Vector2f vec;
    vec.x = 0.f;
    vec.y = 0.f;
    sf::Vector2f vectmp;
    vectmp.x = 0.f;
    vectmp.y = 0.f;
    sf::CircleShape &cs = circle.circleShape;

    vectmp.x = cs.getPosition().x + cs.getRadius() - vector2f.x;
    vectmp.y = cs.getPosition().y + cs.getRadius() - vector2f.y;
    float pythDistance = Math::Pythagoras(vectmp.x, vectmp.y);
    float G = 300;
    float vecValue = (circle.circleMass * G) / (pythDistance * pythDistance);
    float k = vecValue / pythDistance;

    vec.x = k * vectmp.x;
    vec.y = k * vectmp.y;
    circle.vx += vec.x;
    circle.vy += vec.y;
}