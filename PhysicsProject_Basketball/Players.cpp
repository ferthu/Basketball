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
	RM->spriteCache.defaultSpriteSetup("BlackPlayer", "Sprites/BlackPlayer.png");
	RM->spriteCache.defaultSpriteSetup("RedPlayer", "Sprites/RedPlayer.png");

	// Adjust Position
	basePosition = sf::Vector2f(-100.0f, 160);

	RM->getSprite("BlackPlayer").setPosition(basePosition);
	RM->getSprite("RedPlayer").setPosition(basePosition);
}


void Players::update(float delta)
{
	
	
	if (playerTurn == 1)
	{
		if (ball->getActive() && active)
		{
			reset = true;
		}
		else if (!ball->getActive() && reset)
		{
			playerTurn = 2;
			reset = false;
		}
	}
	else if (playerTurn == 2)
	{
		if (ball->getActive() && active)
		{
			reset = true;
		}
		else if (!ball->getActive() && reset)
		{
			playerTurn = 1;
			reset = false;
		}
	}
}

void Players::draw(sf::RenderWindow& window)
{
	
	if (playerTurn == 1 && active)
	{
		window.draw(RM->getSprite("BlackPlayer"));
	}
	else if (playerTurn == 2 && active)
	{ 
		window.draw(RM->getSprite("RedPlayer"));
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

int Players::getPlayerTurn()
{
	return playerTurn;
}

void Players::setPlayerTurn(int playerTurn)
{
	this->playerTurn = playerTurn;
}

bool Players::getReset()
{
	return reset;
}

void Players::setReset(bool reset)
{
	this->reset = reset;
}