//
// Created by starwader on 8/16/17.
//

#include "Move.h"

void Move::update(Circle& c)
{
	c.circleShape.move(c.vx / c.circleMass, c.vy / c.circleMass);
	//c.circleShape.move(c.vx,c.vy);
	c.vx *= 0.999999;
	c.vy *= 0.999999;
}
