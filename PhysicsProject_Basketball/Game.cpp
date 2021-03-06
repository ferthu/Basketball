#include "Game.h"
#include "BasketCollision.h"
#include "PlankCollision.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <iostream>
#include <math.h>

Game::Game()
{
	screenWidth = 1024;
	screenHeight = 600;
	gameOver = false;
	_resource = std::make_shared<ResourceManager>();
}

void Game::settings()
{
	window.create(sf::VideoMode(screenWidth, screenHeight), "Basketball", sf::Style::Default);
	gameState = GAMESTATE::PLAY;
	window.setFramerateLimit(60);


	_entities.push_back(std::make_shared<Basketball_Court>(_resource));
	//_entities.push_back(std::make_shared<Basketball_hoop>(_resource, sf::Vector2f(-1.0f, 0.0f), (float)screenWidth - 150.0f, 0.8f));
	
	hoop = std::make_shared<Basketball_hoop>(_resource);
	basketball = std::make_shared<Basketball>(_resource, pixelsPerMeter);
	_entities.push_back(std::make_shared<Players>(_resource, basketball));
	_entities.push_back(std::make_shared<ScoreSystem>(_resource));
}


void Game::run()
{
	settings();
	initializeGame();
	gameLoop();
}

void Game::gameLoop()
{
	while (gameState == GAMESTATE::PLAY)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameState = GAMESTATE::EXIT;
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				gameState = GAMESTATE::EXIT;
			}
			
			if (!gameOver)
			{
				gameUI->HandleEvents(event);
			}
		}

		time = gameTime.getElapsedTime();

		// slowmotion for debugging
		//update(0.005f);

		// 60 fps
		//update(1.0f / 60.0f);

		// dynamic delta
		update(std::min(gameTime.restart().asSeconds(), 0.02f));

		window.clear(sf::Color(135,206,250,255));
		draw();
		window.display();
	}

	// release resources
	delete gameUI;
}

void Game::initializeGame()
{
	for (auto& i : _entities)
	{
		i->initialize(screenWidth, screenHeight);
	}

	basketball->initialize(screenWidth, screenHeight);
	hoop->pixelsPerMeter = pixelsPerMeter;
	hoop->initialize(screenWidth, screenHeight);
	gameUI = new UI(basketball);

	
	walls[0] = std::make_shared<Wall>(sf::Vector2f(0.0f, 1.0f), 0.0f, 0.95f);					// top
	walls[1] = std::make_shared<Wall>(sf::Vector2f(1.0f, 0.0f), 0.0f, 0.95f);					// left
	walls[2] = std::make_shared<Wall>(sf::Vector2f(0.0f, -1.0f), (float)screenHeight, 0.95f);    // bottom
	walls[3] = std::make_shared<Wall>(sf::Vector2f(-0.5f, 0.0f), (float)screenWidth, 0.95f);	   // right
	basketCollision = std::make_shared<BasketCollision>(hoop->leftOfBasket, hoop->rightOfBasket, 0.95f);
	plankCollision = std::make_shared<PlankCollision>(hoop->topOfPlank.x, hoop->topOfPlank, hoop->bottomOfPlank, 0.95f);
}

void Game::update(float delta)
{
	gameUI->Update(delta);
	basketball->update(delta);
	hoop->update(delta);
	gameOver = hoop->getGameOver();

	if (basketball->getActive())
	{
		for (int i = 0; i < 4; i++)
		{
			walls[i]->checkBallCollision(*basketball, delta);
		}
		basketCollision->checkBallCollision(*basketball, delta);
		plankCollision->checkBallCollision(*basketball, delta);
		hoop->handleHoopCollision(*basketball);
	}

	for (auto& i : _entities)
	{
		i->update(delta);
	}
	

	
}

void Game::draw()
{
	for (auto& i : _entities)
	{
		i->draw(window); 	
	}

	basketball->draw(window);
	hoop->draw(window);
	gameUI->Draw(window);
}