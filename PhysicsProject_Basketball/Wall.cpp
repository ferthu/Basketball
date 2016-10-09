#include "Wall.h"
#include <math.h>

Wall::Wall(sf::Vector2f normal, float distance, float e)
{
	float normalLength = std::sqrtf(normal.x * normal.x + normal.y * normal.y);
	this->normal = sf::Vector2f(normal.x / normalLength, normal.y / normalLength);
	this->distance = distance;
	this->e = e;
}

void Wall::checkBallCollision(Basketball& ball, float pixelsPerMeter, float delta)
{
	ball.handleCollision(normal, distance, e, delta);
}