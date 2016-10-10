#ifndef ENTITY_HPP
#define ENTITY_HPP

//SFML
#include <SFML\graphics.hpp>

// Classes
#include "ResourceManager.h"
#include "drawSprite.h"

// Others
#include <memory>

class Entity
{
public:
	Entity() {}
	Entity(std::shared_ptr<ResourceManager> resourceManager) { this->RM = resourceManager; }
	
	virtual void initialize(int screenWidth, int screenHeight) = 0;
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

protected:
	std::shared_ptr<ResourceManager> RM = std::make_shared<ResourceManager>(); // Resource Manager
	drawSprite* DS; // Draw Sprite
};

#endif
