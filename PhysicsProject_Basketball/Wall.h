#ifndef WALL_H
#define WALL_H

#include "CollisionObject.h"

class Wall : public CollisionObject
{
public:
	Wall(sf::Vector2f normal, float distance, float e);
	virtual void checkHandleBallCollision(Basketball& ball, float pixelsPerMeter);
private:
	sf::Vector2f normal;
	float distance;
	float e;

	Wall();
};

#endif