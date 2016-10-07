#include "Players.h"
#include <iostream>

Players::Players(std::shared_ptr<ResourceManager> resource, std::shared_ptr<Basketball> ball) : Entity(resource)
{
	playerTurn = 1;
	this->ball = ball;
	active = true;
	reset = false;
}

void Players::initialize(int screenWidth, int screenHeight)
{
	// Load Sprites
	RM->spriteCache.defaultSpriteSetup("Player1", "Sprites/Player1.png");
	RM->spriteCache.defaultSpriteSetup("Player2", "Sprites/Player2.png");
	basePosition = sf::Vector2f(-100.0f, 160);
	//// Adjust Position
	RM->getSprite("Player1").setPosition(basePosition);
	RM->getSprite("Player2").setPosition(basePosition);
	
}


void Players::update(float delta)
{
	if (playerTurn == 1)
	{
		if (ball->getActive() && active)
		{
			reset = true;
			RM->getSprite("Player1").move(50.0f * delta, -150.0f * delta);
			std::cout << "x: " << RM->getSprite("Player1").getPosition().x << "y:  " << RM->getSprite("Player1").getPosition().y << std::endl;
			
			if (RM->getSprite("Player1").getPosition().y < 73.5)
			{
				setActive(false);
			}
		}
		else if (ball->getActive() == false && reset)
		{
			RM->getSprite("Player1").setPosition(basePosition);
			playerTurn = 2;
			setActive(true);
			reset = false;
		}
	}
	else if (playerTurn == 2)
	{
		if (ball->getActive() && active)
		{
			reset = true;
			RM->getSprite("Player2").move(50.0f * delta, -150.0f * delta);

			if (RM->getSprite("Player2").getPosition().y < 73.5)
			{
				setActive(false);
			}
		}
		else if (ball->getActive() == false && reset)
		{
			RM->getSprite("Player2").setPosition(basePosition);
			playerTurn = 1;
			setActive(true);
			reset = false;
		}
	}
}

void Players::draw(sf::RenderWindow& window)
{
	// Player Currently not drawing, Have to fix so it works properly.
	if (playerTurn == 1 && active)
	{
		window.draw(RM->getSprite("Player1"));
	}
	else if (playerTurn == 2 && active)
	{ 
		window.draw(RM->getSprite("Player2"));
	}
	
}

bool Players::getActive()
{
	return active;
}

void Players::setActive(bool active)
{
	this->active = active;
}