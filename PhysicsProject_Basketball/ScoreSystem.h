#ifndef SCORESYSTEM_HPP
#define SCORESYSTEM_HPP


#include "Entity.h"

#include <string>

class ScoreSystem : public Entity
{
public:
	ScoreSystem(std::shared_ptr<ResourceManager> resource);
	
	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	
	static void incrementBlackPlayerScore();
	static void incrementRedPlayerScore();
	
	static void decreaseBlackPlayerTriesLeft();
	static void decreaseRedPlayerTriesLeft();
	static void increaseBlackPlayerTriesleft();
	static void increaseRedPlayerTriesLeft();

	// Getters & Setters
	void setMaxTries(int winningScore);
	int getMaxTries();

	void setScoreBoard(std::string scoreboard);
	std::string getScoreBoard();

	static void setCurrBlackPlayerScore(int newCurrBlackPlayerScore);
	static int getCurrBlackPlayerScore();

	static void setCurrRedPlayerScore(int newCurrRedPlayerScore);
	static int getCurrRedPlayerScore();

	static void setRedPlayerTriesLeft(int newRedPlayerTriesLeft);
	static int getRedPlayerTriesLeft();

	static void setBlackPlayerTriesLeft(int newBlackPlayerTriesLeft);
	static int getBlackPlayerTriesLeft();

	static void setBlackPlayerWins(bool win);
	static bool getBlackPlayerWins();

	static void setRedPlayerWins(bool win);
	static bool getRedPlayerWins();

private:
	ScoreSystem() {}
	//How Many points it takes to win
	int maxTries;
	// Winning Player
	static bool blackPlayerWins;
	static bool redPlayerWins;
	// How many tries left
	static int blackPlayerTriesLeft;
	static int redPlayerTriesLeft;
	// The Text that displays the score
	std::string scoreBoard;
	// Current Score of Red Player & Black Player
	static int currBlackPlayerScore;
	static int currRedPlayerScore;

	
};

#endif
