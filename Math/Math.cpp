//
// Created by starwader on 8/17/17.
//

#include "Math.h"
#include <cmath>

float Math::Pythagoras(float x1, float y1, float x2, float y2)
{
	return float(sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2)));
}

float Math::Pythagoras(float x1, float y1)
{
	return float(sqrt(abs(x1) * abs(x1) + abs(y1) * abs(y1)));
}

float Math::CrossProduct(float vec1x, float vec1y, float vec2x, float vec2y)
{
	return vec1x * vec2x + vec1y * vec2y;
}
