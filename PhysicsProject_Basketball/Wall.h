#ifndef WALL_H
#define WALL_H

#include "CollisionObject.h"

class Wall : public CollisionObject
{
public:
	Wall(sf::Vector2f normal, float distance, float e);
	void checkBallCollision(Basketball& ball, float pixelsPerMeter, float delta);
private:
	sf::Vector2f normal;
	float distance;
	float e;

	Wall();
};

#endif