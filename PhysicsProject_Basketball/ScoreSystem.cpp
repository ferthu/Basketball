#include "ScoreSystem.h"

// Initializing Static Members
int ScoreSystem::currBlackPlayerScore = 0;
int ScoreSystem::currRedPlayerScore = 0;
int ScoreSystem::blackPlayerTriesLeft = 5;
int ScoreSystem::redPlayerTriesLeft = 5;
bool ScoreSystem::redPlayerWins = false;
bool ScoreSystem::blackPlayerWins = false;

ScoreSystem::ScoreSystem(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{
	maxTries = 5;
}

void ScoreSystem::initialize(int screenWidth, int screenHeight)
{
	// Setup Score Board Image
	RM->spriteCache.defaultSpriteSetup("ScoreBoard", "Sprites/ScoreBoard.png");
	RM->getSprite("ScoreBoard").setScale(0.25, 0.5);
	RM->getSprite("ScoreBoard").rotate(270);
	RM->getSprite("ScoreBoard").setPosition(810.0f, 130.0f);

	// Setup The Score Text w/ Font.
	RM->textCache.setupText("ScoreBoard", "Fonts/times.ttf");

	// Setup Winning Text For Black & Red Player w/ Font.
	RM->textCache.setupText("BlackPlayerWins", "Fonts/times.ttf");
	RM->textCache.setupText("RedPlayerWins", "Fonts/times.ttf");

	// Attributes For The Score Board Text
	RM->getText("ScoreBoard").setCharacterSize(16);
	RM->getText("ScoreBoard").setStyle(sf::Text::Style::Bold);
	RM->getText("ScoreBoard").setColor(sf::Color::Blue);
	RM->getText("ScoreBoard").setPosition(830.0f, 10.0f);

	// Attributes For Black & Red Player Winning Text
	RM->getText("BlackPlayerWins").setCharacterSize(100);
	RM->getText("BlackPlayerWins").setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	RM->getText("BlackPlayerWins").setColor(sf::Color::Black);
	RM->getText("BlackPlayerWins").setPosition(screenWidth / 8.0f, screenHeight / 2.0f);
	RM->getText("BlackPlayerWins").setString("BLACK PLAYER\n\t\tWINS!!!");

	RM->getText("RedPlayerWins").setCharacterSize(100);
	RM->getText("RedPlayerWins").setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
	RM->getText("RedPlayerWins").setColor(sf::Color::Red);
	RM->getText("RedPlayerWins").setPosition(screenWidth / 8.0f, screenHeight / 2.5f);
	RM->getText("RedPlayerWins").setString("RED PLAYER\n\t\tWINS!!!");
}
void ScoreSystem::update(float delta)
{
	scoreBoard = "\t\t\t  Rules\n" + std::to_string(maxTries) + " Shots each."
		"\nSudden Death if tied."
		"\n\nBlack Player: " + std::to_string(currBlackPlayerScore) + "\n"
		"Red Player: " + std::to_string(currRedPlayerScore);

	RM->getText("ScoreBoard").setString(scoreBoard);
}

void ScoreSystem::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("ScoreBoard"));
	window.draw(RM->getText("ScoreBoard"));
	
	if (getBlackPlayerWins())
	{
		window.draw(RM->getText("BlackPlayerWins"));
	}
	else if (getRedPlayerWins())
	{
		window.draw(RM->getText("RedPlayerWins"));
	}
}

void ScoreSystem::setBlackPlayerWins(bool win)
{
	blackPlayerWins = win;
}

bool ScoreSystem::getBlackPlayerWins()
{
	return blackPlayerWins;
}

void ScoreSystem::setRedPlayerWins(bool win)
{
	redPlayerWins = win;
}

bool ScoreSystem::getRedPlayerWins()
{
	return redPlayerWins;
}

void ScoreSystem::setMaxTries(int maxTries)
{
	if (blackPlayerTriesLeft > 0 && redPlayerTriesLeft > 0)
	{
		this->maxTries = maxTries;
	}
	else 
	{
		blackPlayerTriesLeft = maxTries;
		redPlayerTriesLeft = maxTries;
		this->maxTries = maxTries;
	}
}

int ScoreSystem::getMaxTries()
{
	return maxTries;
}

void ScoreSystem::setScoreBoard(std::string scoreboard)
{
	this->scoreBoard = scoreboard;
}
std::string ScoreSystem::getScoreBoard()
{
	return scoreBoard;
}

void ScoreSystem::setCurrBlackPlayerScore(int newCurrBlackPlayerScore)
{
	currBlackPlayerScore = newCurrBlackPlayerScore;
}
int ScoreSystem::getCurrBlackPlayerScore()
{
	return currBlackPlayerScore;
}

void ScoreSystem::setCurrRedPlayerScore(int newCurrRedPlayerScore)
{
	currRedPlayerScore = newCurrRedPlayerScore;
}
int ScoreSystem::getCurrRedPlayerScore()
{
	return currRedPlayerScore;
}

void ScoreSystem::setBlackPlayerTriesLeft(int newBlackPlayerTriesLeft)
{
	blackPlayerTriesLeft = newBlackPlayerTriesLeft;
}

int ScoreSystem::getBlackPlayerTriesLeft()
{
	return blackPlayerTriesLeft;
}

void ScoreSystem::setRedPlayerTriesLeft(int newRedPlayerTriesLeft)
{
	redPlayerTriesLeft = newRedPlayerTriesLeft;
}

int ScoreSystem::getRedPlayerTriesLeft()
{
	return redPlayerTriesLeft;
}

void ScoreSystem::incrementBlackPlayerScore()
{
	currBlackPlayerScore++;
}

void ScoreSystem::incrementRedPlayerScore()
{
	currRedPlayerScore++;
}

void ScoreSystem::decreaseBlackPlayerTriesLeft()
{
	if (blackPlayerTriesLeft > 0)
	{
		blackPlayerTriesLeft--;
	}
}

void ScoreSystem::increaseBlackPlayerTriesleft()
{
	blackPlayerTriesLeft++;
}

void ScoreSystem::decreaseRedPlayerTriesLeft()
{
	if (redPlayerTriesLeft > 0 )
	{
		redPlayerTriesLeft--;
	}
}

void ScoreSystem::increaseRedPlayerTriesLeft()
{
	redPlayerTriesLeft++;
}