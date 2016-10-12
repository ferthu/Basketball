#ifndef GAME_HPP
#define GAME_HPP

//SFML
#include <SFML\graphics.hpp>

#include "Players.h"
#include "Basketball_hoop.h"
#include "Basketball_Court.h"
#include "Basketball.h"
#include "ScoreSystem.h"
#include "Entity.h"
#include "UI.h"
#include "Wall.h"
#include "CollisionObject.h"
#include "BasketCollision.h"
#include "PlankCollision.h"

#include <vector>

class Game
{
public:
	Game();
	// Starts everything.
	void run();

private:
	// Initializes SFML Screen & Settings.
	void settings(); 
	// Initialize sprites and such
	void initializeGame();
	// Loops the game.
	void gameLoop(); 
	// Updates The Game
	void update(float delta);
	// Draws The Game
	void draw();

	// game UI
	UI* gameUI;

	// basketball
	std::shared_ptr<Basketball> basketball;
	std::shared_ptr<Basketball_hoop> hoop;
	
	// The Game Window
	sf::RenderWindow window;

	// Game Window Resolution
	int screenWidth, screenHeight;

	// States of the game.
	enum class GAMESTATE { PLAY, EXIT };
	GAMESTATE gameState;

	// SFML Variables
	sf::Clock gameTime;
	sf::Event event;
	sf::Time time;
	
	std::shared_ptr<ResourceManager> _resource; 
	std::vector<std::shared_ptr<Entity>> _entities;

	const float pixelsPerMeter = 100.0f;

	//Walls
	std::shared_ptr<Wall> walls[4];

	// basket collision
	std::shared_ptr<BasketCollision> basketCollision;
	// plank collision
	std::shared_ptr<PlankCollision> plankCollision;

	// Game Ends
	bool gameOver;
	
};
#endif