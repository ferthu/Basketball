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
	redPlayerLost = false;
	blackPlayerLost = false;
	rpm = false;
	bpm = false;
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

	//if (ScoreSystem::getCurrBlackPlayerScore() == tempBlackPlayerScore + 1) // Black Player Scores
	//{
	//	bpm = false;
	//	tempBlackPlayerScore = ScoreSystem::getCurrBlackPlayerScore();
	//}
	//else if (ScoreSystem::getCurrBlackPlayerScore() == tempBlackPlayerScore && ball->getFail() == false )// Black Player Missed
	//{
	//	
	//	if (playerTurn == 1)
	//	{
	//		if (ball->getFail() && !active)
	//		{
	//				bpm = true;
	//		}
	//	}
	//	
	//}

	//if (ScoreSystem::getCurrRedPlayerScore() == tempRedPlayerScore + 1) // Red Player Scores
	//{
	//	if (bpm)
	//	{
	//		ScoreSystem::setRedPlayerWins(true);
	//		gameOver = true;
	//	}

	//	
	//	tempRedPlayerScore = ScoreSystem::getCurrRedPlayerScore();
	//}
	//else if (ScoreSystem::getCurrRedPlayerScore() == tempRedPlayerScore && ball->getFail() == false)
	//{
	//	if (playerTurn == 2)
	//	{
	//		if (ball->getFail() && !active)
	//		{
	//			rpm = true;
	//		}
	//	}
	//}

	//if (rpm)
	//{
	//	ScoreSystem::setBlackPlayerWins(true);
	//	gameOver = true;
	//}
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