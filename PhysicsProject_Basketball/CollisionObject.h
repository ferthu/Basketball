#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Basketball.h"

class CollisionObject
{
public:
	CollisionObject() {};
	virtual void checkHandleBallCollision(Basketball& ball, float pixelsPerMeter) = 0;
private:
};

#endif