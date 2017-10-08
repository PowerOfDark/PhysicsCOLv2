//
// Created by starwader on 8/16/17.
//

#ifndef COLLISIONSSFML_GRAVITY_H
#define COLLISIONSSFML_GRAVITY_H

#include "../Entity/Circle.h"

namespace Gravity {
    void Attract(Circle &c1, Circle &c2);

    void Reject(sf::Vector2f &, Circle &);
};


#endif //COLLISIONSSFML_GRAVITY_H
