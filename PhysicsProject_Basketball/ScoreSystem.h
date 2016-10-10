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
	
	void setWinningScore(int winningScore);
	int getWinningScore();

	void setScoreBoard(std::string scoreboard);
	std::string getScoreBoard();

	static void incrementBlackPlayerScore();
	static void incrementRedPlayerScore();
	

private:
	ScoreSystem() {}
	//How Many points it takes to win
	int winningScore;
	// The Text that displays the score
	std::string scoreBoard;
	// Current Score of Red Player & Black Player
	static int currBlackPlayerScore;
	static int currRedPlayerScore;
	
};

#endif
