#include "Game.h"
#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <iostream>

Game::Game()
{
	screenWidth = 1024;
	screenHeight = 600;

	_resource = std::make_shared<ResourceManager>();
}

void Game::settings()
{
	window.create(sf::VideoMode(screenWidth, screenHeight), "Basketball", sf::Style::Default);
	gameState = GAMESTATE::PLAY;
	window.setFramerateLimit(60);


	_entities.push_back(std::make_shared<Basketball_Court>(_resource));
	_entities.push_back(std::make_shared<Basketball_hoop>(_resource));
	_entities.push_back(std::make_shared<ScoreSystem>(_resource));
	basketball = std::make_shared<Basketball>(_resource, pixelsPerMeter);
	_entities.push_back(std::make_shared<Players>(_resource, basketball));
	

	
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
			else
			{
				gameUI->HandleEvents(event);
			}
		}

		time = gameTime.getElapsedTime();
		update(gameTime.restart().asSeconds());
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

	gameUI = new UI(basketball);

	
	walls[0] = std::make_shared<Wall>(sf::Vector2f(0.0f, 1.0f), 0.0f, 0.8f);					// top
	walls[1] = std::make_shared<Wall>(sf::Vector2f(1.0f, 0.0f), 0.0f, 0.8f);					// left
	walls[2] = std::make_shared<Wall>(sf::Vector2f(0.0f, -1.0f), (float)screenHeight, 0.8f);    // bottom
	walls[3] = std::make_shared<Wall>(sf::Vector2f(-0.5f, 0.0f), (float)screenWidth, 0.8f);	   // right
}

void Game::update(float delta)
{
	for (auto& i : _entities)
	{
		i->update(delta);
	}
	gameUI->Update(delta);
	basketball->update(delta);

	if (basketball->getActive())
	{
		for (int i = 0; i < 4; i++)
		{
			walls[i]->checkBallCollision(*basketball, pixelsPerMeter, delta);
		}
	}
}

void Game::draw()
{
	for (auto& i : _entities)
	{
		i->draw(window); 	
	}

	basketball->draw(window);
	gameUI->Draw(window);
}