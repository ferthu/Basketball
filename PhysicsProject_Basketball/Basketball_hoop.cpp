#include "Basketball_hoop.h"
#include <iostream>
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