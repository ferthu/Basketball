#include "BasketCollision.h"
#include "Basketball.h"
#include "VectorFunctions.h"

BasketCollision::BasketCollision(sf::Vector2f leftPosition, sf::Vector2f rightPosition, float e)
{
	this->leftPosition = leftPosition;
	this->rightPosition = rightPosition;
	this->e = e;
}

void BasketCollision::checkBallCollision(Basketball& ball, float delta)
{
	sf::Vector2f leftNormal = normalize(ball.getPosition() - leftPosition);
	sf::Vector2f rightNormal = normalize(ball.getPosition() - rightPosition);

	ball.handleCollision(leftNormal, -dot(leftNormal, leftPosition), e, delta);
	ball.handleCollision(rightNormal, -dot(rightNormal, rightPosition), e, delta);
}