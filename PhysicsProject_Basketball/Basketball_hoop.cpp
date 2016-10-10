#include "Basketball_hoop.h"
#include <math.h>
#include <iostream>

Basketball_hoop::Basketball_hoop(sf::Vector2f normal, float distance, float e)
{
	float normalLenght = std::sqrtf(normal.x * normal.x + normal.y * normal.y);
	this->normal = sf::Vector2f(normal.x / normalLenght, normal.y / normalLenght);
	this->distance = distance;
	this->e = e;
}

void Basketball_hoop::initialize(int screenWidth, int screenHeight)
{
	// Load Sprite
	RM->spriteCache.defaultSpriteSetup("basketball_hoop", "Sprites/hoop.png");
	// Scale The Image
	
	//// Adjust Position
	RM->getSprite("basketball_hoop").setPosition(RM->getSprite("basketball_hoop").getPosition().x + 700, RM->getSprite("basketball_hoop").getPosition().y + 163);
}

void Basketball_hoop::update(float delta)
{
	// Empty
}

void Basketball_hoop::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball_hoop"));
}

sf::Sprite& Basketball_hoop::getSprite()
{
	return RM->getSprite("basketball_hoop");
}

void Basketball_hoop::checkBallCollision(Basketball& ball, float pixelsPerMeter, float delta)
{
	
}