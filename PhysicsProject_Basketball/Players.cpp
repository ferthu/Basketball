#include "Players.h"
#include <iostream>

int Players::playerTurn = 1;
bool Players::reset = false;
bool Players::gameOver = false;
Players::Players(std::shared_ptr<ResourceManager> resource, std::shared_ptr<Basketball> ball) : Entity(resource)
{

	this->ball = ball;
	active = true;
	startSuddenDeath = false;
	counter = 0;

	blackPlayerScored = false;

	tempBlackPlayerScore = -1;
	tempRedPlayerScore = -1;
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
	if (startSuddenDeath == false)
	{
		victory();
	}
	
	checkIfSuddenDeath();

	if (playerTurn == 1)
	{
		// When Player 1 presses start
		if (ball->getActive() && active)
		{
			reset = true;
			setActive(false);
			ScoreSystem::decreaseBlackPlayerTriesLeft();
			std::cout << "Black Player Tries Left: " << ScoreSystem::getBlackPlayerTriesLeft() << std::endl;
		}
		// When player 1 presses reset
		else if (!ball->getActive() && reset)
		{
			playerTurn = 2;
			reset = false;
			setActive(true);
			ball->setScored(false);
			ball->setFail(true);
		}
	}
	else if (playerTurn == 2)
	{
		// When player 2 presses start
		if (ball->getActive() && active)
		{
			reset = true;
			setActive(false);
			ScoreSystem::decreaseRedPlayerTriesLeft();
			std::cout << "Red Player Tries Left: " << ScoreSystem::getRedPlayerTriesLeft() << std::endl;
		}
		// When player 2 presses reset
		else if (!ball->getActive() && reset)
		{
			playerTurn = 1;
			reset = false;
			setActive(true);
			ball->setScored(false);
			ball->setFail(true);
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

void Players::victory()
{

	if (ScoreSystem::getBlackPlayerTriesLeft() == 0 && ScoreSystem::getCurrRedPlayerScore() > ScoreSystem::getCurrBlackPlayerScore())
	{
		if (ball->getFail())
		{
			ScoreSystem::setRedPlayerWins(true);
			gameOver = true;
		}


	}
	else if (ScoreSystem::getRedPlayerTriesLeft() == 0 && ScoreSystem::getCurrBlackPlayerScore() > ScoreSystem::getCurrRedPlayerScore())
	{
		if (ball->getFail())
		{
			std::cout << "Normal Win" << std::endl;
			ScoreSystem::setBlackPlayerWins(true);
			gameOver = true;
		}

	}
}

void Players::checkIfSuddenDeath()
{
	if (ScoreSystem::getBlackPlayerTriesLeft() == 0 && ScoreSystem::getRedPlayerTriesLeft() == 0)
	{
		if (ScoreSystem::getCurrBlackPlayerScore() == ScoreSystem::getCurrRedPlayerScore())
		{
			startSuddenDeath = true;
		}
	}

	if (startSuddenDeath == true)
	{
		suddenDeath();
	}
}

void Players::suddenDeath()
{
	if (tempBlackPlayerScore == -1 && tempRedPlayerScore == -1)
	{
		tempBlackPlayerScore = ScoreSystem::getCurrBlackPlayerScore();
		tempRedPlayerScore = ScoreSystem::getCurrRedPlayerScore();
	}

	if (ball->getActive())
	{
		
			if (playerTurn == 1)
			{
				if (ScoreSystem::getCurrBlackPlayerScore() == tempBlackPlayerScore + 1) // Black Player Scores
				{
					tempBlackPlayerScore = ScoreSystem::getCurrBlackPlayerScore();
					blackPlayerScored = true;
				}
				else
				{
					if (!ball->getScored() && ball->getFail())
					{
						blackPlayerScored = false;
					}
				}
			}
			else if (playerTurn == 2)
			{
				if (ScoreSystem::getCurrRedPlayerScore() == tempRedPlayerScore + 1) // Red Player Scores
				{
					tempRedPlayerScore = ScoreSystem::getCurrRedPlayerScore();

					if (blackPlayerScored == false)
					{
						ScoreSystem::setRedPlayerWins(true);
						gameOver = true;
					}
				}
				else
				{
					if (!ball->getScored() && ball->getFail())
					{
						if (blackPlayerScored == true)
						{
							std::cout << "Sudden Death Win" << std::endl;
							ScoreSystem::setBlackPlayerWins(true);
							gameOver = true;
						}
					}
				}
			}
		
	}
}

void Players::setGameOver(bool newGameOver)
{
	gameOver = newGameOver;
}

bool Players::getGameOver()
{
	return gameOver;
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

void Players::setPlayerTurn(int newPlayerTurn)
{
	playerTurn = newPlayerTurn;
}

bool Players::getReset()
{
	return reset;
}

void Players::setReset(bool reset)
{
	reset = reset;
}