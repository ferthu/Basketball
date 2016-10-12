#ifndef PLANKCOLLISION_H
#define PLANKCOLLISION_H

#include "Entity.h"
#include "Basketball.h"
#include "CollisionObject.h"

class PlankCollision : public CollisionObject
{
public:
	PlankCollision(float xPosition, sf::Vector2f topEdge, sf::Vector2f bottomEdge, float e);
	void checkBallCollision(Basketball& ball, float delta);
private:
	float e;
	float xPosition;
	sf::Vector2f topEdge, bottomEdge;
	PlankCollision();
};

#endif