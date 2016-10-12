#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "Basketball.h"

class CollisionObject
{
public:
	CollisionObject() {};
	virtual void checkBallCollision(Basketball& ball, float delta) = 0;
private:
};

#endif