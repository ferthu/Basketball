#ifndef BASKETCOLLISION_H
#define BASKETCOLLISION_H

#include "Entity.h"
#include "Basketball.h"
#include "CollisionObject.h"

class BasketCollision : public CollisionObject
{
public:
	BasketCollision(sf::Vector2f leftPosition, sf::Vector2f rightPosition, float e);
	void checkBallCollision(Basketball& ball, float delta);
private:
	float e;
	sf::Vector2f leftPosition, rightPosition;
	BasketCollision();
};

#endif