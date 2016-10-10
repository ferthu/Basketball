#include "ScoreSystem.h"

// Initializing Static Members
int ScoreSystem::currBlackPlayerScore = 0;
int ScoreSystem::currRedPlayerScore = 0;

ScoreSystem::ScoreSystem(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{
	winningScore = 5;
	
	scoreBoard = "Score - First To " + std::to_string(winningScore) + " Wins"
		"\n\nBlack Player: " + std::to_string(currBlackPlayerScore) + "\n\n"
		"Red Player: " + std::to_string(currRedPlayerScore);
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

	// Attributes For The Text
	
	RM->getText("ScoreBoard").setCharacterSize(16);
	RM->getText("ScoreBoard").setStyle(sf::Text::Style::Bold);
	RM->getText("ScoreBoard").setColor(sf::Color::Magenta);
	RM->getText("ScoreBoard").setPosition(830.0f, 10.0f);


}
void ScoreSystem::update(float delta)
{
	
	scoreBoard = "Score - First To " + std::to_string(winningScore) + " Wins"
		"\n\nBlack Player: " + std::to_string(currBlackPlayerScore) + "\n\n"
		"Red Player: " + std::to_string(currRedPlayerScore);

	RM->getText("ScoreBoard").setString(scoreBoard);
}

void ScoreSystem::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("ScoreBoard"));
	window.draw(RM->getText("ScoreBoard"));
}

void ScoreSystem::setWinningScore(int winningScore)
{
	this->winningScore = winningScore;
}

int ScoreSystem::getWinningScore()
{
	return winningScore;
}

void ScoreSystem::setScoreBoard(std::string scoreboard)
{
	this->scoreBoard = scoreboard;
}
std::string ScoreSystem::getScoreBoard()
{
	return scoreBoard;
}

void ScoreSystem::incrementBlackPlayerScore()
{
	currBlackPlayerScore++;
}

void ScoreSystem::incrementRedPlayerScore()
{
	currRedPlayerScore++;
}
