#include "PlankCollision.h"
#include "Basketball.h"
#include "VectorFunctions.h"

PlankCollision::PlankCollision(float xPosition, sf::Vector2f topEdge, sf::Vector2f bottomEdge, float e)
{
	this->xPosition = xPosition;
	this->topEdge = topEdge;
	this->bottomEdge = bottomEdge;
	this->e = e;
}

void PlankCollision::checkBallCollision(Basketball& ball, float delta)
{
	// above plank
	if (ball.getPosition().y < topEdge.y)
	{
		sf::Vector2f topNormal = normalize(ball.getPosition() - topEdge);
		ball.handleCollision(topNormal, -dot(topNormal, topEdge), e, delta);
	}
	// below plank
	else if (ball.getPosition().y > bottomEdge.y)
	{
		sf::Vector2f bottomNormal = normalize(ball.getPosition() - bottomEdge);
		ball.handleCollision(bottomNormal, -dot(bottomNormal, bottomEdge), e, delta);
	}
	// level with plank
	else
	{
		// left of plank
		if (ball.getPosition().x <= topEdge.x)
		{
			ball.handleCollision(sf::Vector2f(-1.0f, 0.0f), xPosition, e, delta);
		}
		// right of plank
		else
		{
			ball.handleCollision(sf::Vector2f(1.0f, 0.0f), -xPosition, e, delta);
		}
	}
}