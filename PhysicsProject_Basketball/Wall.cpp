#include "Wall.h"
#include <math.h>

Wall::Wall(sf::Vector2f normal, float distance, float e)
{
	float normalLength = std::sqrtf(normal.x * normal.x + normal.y * normal.y);
	this->normal = sf::Vector2f(normal.x / normalLength, normal.y / normalLength);
	this->distance = distance;
	this->e = e;
}

void Wall::checkHandleBallCollision(Basketball& ball, float pixelsPerMeter)
{
	float positionDot = normal.x * ball.getPosition().x + normal.y * ball.getPosition().y;
	float velocityDot = normal.x * ball.getVelocity().x + normal.y * ball.getVelocity().y;

	// collision
	if (positionDot <= (ball.getRadius() * pixelsPerMeter - distance) && velocityDot < 0)
	{
		// move out of wall
		ball.setPosition(ball.getPosition() + normal * ((ball.getRadius() * pixelsPerMeter - distance) - positionDot));

		float newLineOfActionVelocity = -velocityDot * e;

		ball.setVelocity(ball.getVelocity() + normal * (newLineOfActionVelocity - velocityDot));
	}
}