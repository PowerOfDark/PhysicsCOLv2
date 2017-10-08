//
// Created by starwader on 8/16/17.
//

#ifndef PONGSFML_COLLISIONS_H
#define PONGSFML_COLLISIONS_H

#include <SFML/Graphics.hpp>
#include "../Entity/Circle.h"

namespace Collision {

    bool DetectCollision(Circle &c1, Circle &c2);

    void Collide(Circle &c1, Circle &c2);

    void DetectWallCollision(Circle &c1, sf::RenderWindow &window);
};

#endif //PONGSFML_COLLISIONS_H
