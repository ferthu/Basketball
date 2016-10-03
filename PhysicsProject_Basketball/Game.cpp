#include "Game.h"
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
	_entities.push_back(std::make_shared<Basketball>(_resource));
	_entities.push_back(std::make_shared<Basketball_hoop>(_resource));
	

	
	
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
		}

		time = gameTime.getElapsedTime();
		update(gameTime.restart().asSeconds());
		window.clear(sf::Color(135,206,250,255));
		draw();
		window.display();
	}
}

void Game::initializeGame()
{
	for (auto& i : _entities)
	{
		i->initialize(screenWidth, screenHeight);
	}
}

void Game::update(float delta)
{
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

}