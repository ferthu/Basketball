#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Entity.h"

#include "Basketball.h"
#include "ScoreSystem.h"

class Players : public Entity
{
public:
	Players(std::shared_ptr<ResourceManager> resource, std::shared_ptr<Basketball> ball);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	sf::Sprite& getSprite() { sf::Sprite sprite; return sprite; }

	bool getActive();
	void setActive(bool active);

	static int getPlayerTurn();
	static void setPlayerTurn(int newPlayerTurn);

	static bool getReset();
	static void setReset(bool reset);

	void checkIfSuddenDeath();
	void suddenDeath();

	static void setGameOver(bool newGameOver);
	static bool getGameOver();

private:
	static int playerTurn;
	bool active;
	static bool reset; // True if the reset button was hit. Then it goes back to false.
	bool startSuddenDeath;
	static bool gameOver;
	bool redPlayerLost;
	bool blackPlayerLost;
	bool rpm;
	bool bpm;
	std::shared_ptr<Basketball> ball;
	sf::Vector2f basePosition;
	int counter;
	int tempBlackPlayerScore;
	int tempRedPlayerScore;
};
#endif
