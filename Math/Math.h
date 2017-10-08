//
// Created by starwader on 8/17/17.
//

#ifndef PONGSFML_MATH_H
#define PONGSFML_MATH_H

class Math {
public:
    static float Pythagoras(float x1, float y1, float x2, float y2);

    static float Pythagoras(float x1, float y1);

    static float CrossProduct(float vec1x, float vec1y, float vec2x, float vec2y);
};

#endif //PONGSFML_MATH_H
