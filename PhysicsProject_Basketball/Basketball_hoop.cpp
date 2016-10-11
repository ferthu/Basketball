#include "Basketball_hoop.h"
#include <math.h>
#include <iostream>


Basketball_hoop::Basketball_hoop(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{
	
}

void Basketball_hoop::initialize(int screenWidth, int screenHeight)
{
	// Load Sprite
	RM->spriteCache.defaultSpriteSetup("basketball_hoop", "Sprites/hoop.png");

	// Scale The Image
	float hoopHeightInMeters = 544.0f / 440.0f * 3.048f;
	sf::Vector2u textureSize = RM->getSprite("basketball_hoop").getTexture()->getSize();
	RM->getSprite("basketball_hoop").setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	size = hoopHeightInMeters * pixelsPerMeter / textureSize.x / 2.0f;
	RM->getSprite("basketball_hoop").setScale(size, size);

	// Adjust Position
	RM->getSprite("basketball_hoop").setPosition(screenWidth - size * textureSize.x, 
		screenHeight - size * textureSize.y);

	// Calculate Positions for Hoop Basket & Plank
	leftOfBasket = RM->getSprite("basketball_hoop").getPosition() + sf::Vector2f(4.0f, 104.0f) * size;
	rightOfBasket = RM->getSprite("basketball_hoop").getPosition() + sf::Vector2f(70.0f, 104.0f) * size;

	bottomOfPlank = RM->getSprite("basketball_hoop").getPosition() + sf::Vector2f(87.0f, 120.0f) * size;
	topOfPlank = RM->getSprite("basketball_hoop").getPosition() + sf::Vector2f(87.0f, 3.0f) * size;
}

void Basketball_hoop::update(float delta)
{
	setRectangleShape(sf::Vector2f(932.5, 215), sf::Vector2f(50.0f, 3.0f), sf::Color::Red);
	
}

void Basketball_hoop::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball_hoop"));
	window.draw(basketCollisionRect);
}

sf::Sprite& Basketball_hoop::getSprite()
{
	return RM->getSprite("basketball_hoop");
}

void Basketball_hoop::setRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
	basketCollisionRect.setPosition(leftOfBasket);
	basketCollisionRect.setSize(size);
	basketCollisionRect.setFillColor(color);
}

void Basketball_hoop::handleHoopCollision(Basketball& ball)
{
	if (!ball.getFail())
	{
		if ((ball.getPosition().x - 12.0f) > leftOfBasket.x && ball.getPosition().x + 8.0f < rightOfBasket.x)
		{
			if (ball.getPosition().y + 12.0f > leftOfBasket.y && ball.getPosition().y - 12.0f < leftOfBasket.y)
			{
				if (Players::getPlayerTurn() == 1)
				{
					ScoreSystem::incrementBlackPlayerScore();
					ball.setFail(true);
				}
				else if (Players::getPlayerTurn() == 2)
				{
					ScoreSystem::incrementRedPlayerScore();
					ball.setFail(true);
				}
			}
		}
	}
}

bool Basketball_hoop::getGameOver()
{
	return Players::getGameOver();
}