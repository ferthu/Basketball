#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Basketball.h"

class CollisionObject
{
public:
	CollisionObject() {};
	float frictionCoefficient;
	virtual void checkBallCollision(Basketball& ball, float pixelsPerMeter, float delta) = 0;
private:
};

#endif