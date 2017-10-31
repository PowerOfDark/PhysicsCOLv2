//
// Created by starwader on 8/16/17.
//

#include <cmath>
#include "Collisions.h"
#include "../../Math/Math.h"

bool Collision::DetectCollision(Circle& c1, Circle& c2)
{
	float distance = Math::Pythagoras(c1.getEdgeX(), c1.getEdgeY(),
		c2.getEdgeX(), c2.getEdgeY());
	return distance <= (c1.getRadius() + c2.getRadius());
}

void Collision::Collide(Circle& c1, Circle& c2)
{
	float vec1x = c2.getEdgeX() - c1.getEdgeX();
	float vec1y = c2.getEdgeY() - c1.getEdgeY();
	float pythDistance = Math::Pythagoras(vec1x, vec1y);
	float offsetDistance = fabsf(pythDistance - c1.getRadius() - c2.getRadius());
	sf::Vector2f offset;
	float k = offsetDistance / pythDistance;
	offset.x = k * vec1x;
	offset.y = k * vec1y;
	c1.circleShape.move(-offset.x / 2, -offset.y / 2);
	c2.circleShape.move(offset.x / 2, offset.y / 2);

	//zac - c1
	//vec1 - temporary vector

	vec1x = c2.getEdgeX() - c1.getEdgeX();
	vec1y = c2.getEdgeY() - c1.getEdgeY();
	//float angle = acosf(Math::ScalarProduct(vec1x,vec1y,c1.vx-c2.vx,c1.vy-c2.vy)/(Math::Pythagoras(vec1x,vec1y)*Math::Pythagoras(c1.vx-c2.vx,c1.vy-c2.vy)));
	float newvlength = (Math::CrossProduct(vec1x, vec1y, c1.vx - c2.vx, c1.vy - c2.vy) /
			(Math::Pythagoras(vec1x, vec1y) * Math::Pythagoras(c1.vx - c2.vx, c1.vy - c2.vy))) *
		Math::Pythagoras(c1.vx - c2.vx, c1.vy - c2.vy);
	float z = newvlength / Math::Pythagoras(vec1x, vec1y);
	//printf("angle: %f\nnewvlength: %f\nz: %f\n",angle,newvlength,z);
	//z=fabsf(z);

	if (z > 0)
	{
		c2.vx += z * vec1x;
		c2.vy += z * vec1y;
		c1.vx -= z * vec1x;
		c1.vy -= z * vec1y;
	}
}

void Collision::DetectWallCollision(Circle& c1, sf::RenderWindow& window)
{
	float wx = window.getSize().x;
	float wy = window.getSize().y;
	float cx = c1.getPosX();
	float cy = c1.getPosY();

	if (cx <= 0)
	{
		c1.vx = -c1.vx;
		cx = 0.01f;
	}
	if (cx >= wx)
	{
		c1.vx = -c1.vx;
		cx = wx - c1.getRadius() - 0.01f;
	}
	if (cy <= 0)
	{
		c1.vy = -c1.vy;
		cy = 0.01f;
	}
	if (cy >= wy)
	{
		c1.vy = -c1.vy;
		cy = wy - c1.getRadius() - 0.01f;
	}
	c1.setPosition(cx, cy);
}
