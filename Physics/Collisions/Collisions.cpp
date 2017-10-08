//
// Created by starwader on 8/16/17.
//

#include <cmath>
#include "Collisions.h"
#include "../../Math/Math.h"

bool Collision::DetectCollision(Circle &c1, Circle &c2) {
    if (Math::Pythagoras(
            c1.circleShape.getPosition().x + c1.circleShape.getRadius(),
            c1.circleShape.getPosition().y + c1.circleShape.getRadius(),
            c2.circleShape.getPosition().x + c2.circleShape.getRadius(),
            c2.circleShape.getPosition().y + c2.circleShape.getRadius()) <=
        c1.circleShape.getRadius() + c2.circleShape.getRadius()) {

        return 1;
    } else {
        return 0;
    }
}

void Collision::Collide(Circle &c1, Circle &c2) {
    float vec1x = c2.circleShape.getPosition().x + c2.circleShape.getRadius() - c1.circleShape.getPosition().x -
                  c1.circleShape.getRadius();
    float vec1y = c2.circleShape.getPosition().y + c2.circleShape.getRadius() - c1.circleShape.getPosition().y -
                  c1.circleShape.getRadius();
    float pythDistance = Math::Pythagoras(vec1x, vec1y);
    float offsetDistance = fabsf(pythDistance - c1.circleShape.getRadius() - c2.circleShape.getRadius());
    sf::Vector2f offset;
    float k = offsetDistance / pythDistance;
    offset.x = k * vec1x;
    offset.y = k * vec1y;
    c1.circleShape.move(-offset.x / 2, -offset.y / 2);
    c2.circleShape.move(offset.x / 2, offset.y / 2);

    //zac - c1
    //vec1 - temporary vector

    vec1x = c2.circleShape.getPosition().x + c2.circleShape.getRadius() - c1.circleShape.getPosition().x -
            c1.circleShape.getRadius();
    vec1y = c2.circleShape.getPosition().y + c2.circleShape.getRadius() - c1.circleShape.getPosition().y -
            c1.circleShape.getRadius();
    //float angle = acosf(Math::ScalarProduct(vec1x,vec1y,c1.vx-c2.vx,c1.vy-c2.vy)/(Math::Pythagoras(vec1x,vec1y)*Math::Pythagoras(c1.vx-c2.vx,c1.vy-c2.vy)));
    float newvlength = (Math::CrossProduct(vec1x, vec1y, c1.vx - c2.vx, c1.vy - c2.vy) /
                        (Math::Pythagoras(vec1x, vec1y) * Math::Pythagoras(c1.vx - c2.vx, c1.vy - c2.vy))) *
                       Math::Pythagoras(c1.vx - c2.vx, c1.vy - c2.vy);
    float z = newvlength / Math::Pythagoras(vec1x, vec1y);
    //printf("angle: %f\nnewvlength: %f\nz: %f\n",angle,newvlength,z);
    //z=fabsf(z);

    if (z > 0) {
        c2.vx += z * vec1x;
        c2.vy += z * vec1y;
        c1.vx -= z * vec1x;
        c1.vy -= z * vec1y;
    }


}

void Collision::DetectWallCollision(Circle &c1, sf::RenderWindow &window) {
    if (c1.circleShape.getPosition().x <= 0) {
        c1.vx = -c1.vx;
        c1.circleShape.setPosition(0.01f, c1.circleShape.getPosition().y);
    }
    if (c1.circleShape.getRadius() * 2 + c1.circleShape.getPosition().x >= window.getSize().x) {
        c1.vx = -c1.vx;
        c1.circleShape.setPosition(window.getSize().x - 0.01f - c1.circleShape.getRadius() * 2,
                                   c1.circleShape.getPosition().y);
    }
    if (c1.circleShape.getPosition().y <= 0) {
        c1.vy = -c1.vy;
        c1.circleShape.setPosition(c1.circleShape.getPosition().x, 0.01f);
    }
    if (c1.circleShape.getRadius() * 2 + c1.circleShape.getPosition().y >= window.getSize().y) {
        c1.vy = -c1.vy;
        c1.circleShape.setPosition(c1.circleShape.getPosition().x,
                                   window.getSize().y - 0.01f - c1.circleShape.getRadius() * 2);
    }
}

