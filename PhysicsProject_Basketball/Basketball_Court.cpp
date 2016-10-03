#include "Basketball_Court.h"
#include <iostream>
void Basketball_Court::initialize(int screenWidth, int screenHeight)
{
	// Load Sprite
	RM->spriteCache.defaultSpriteSetup("basketball_court", "Sprites/rsz_Background.png");
	// Scale The Image
	RM->getSprite("basketball_court").setScale(screenWidth / RM->getSprite("basketball_court").getLocalBounds().width,
		screenHeight / RM->getSprite("basketball_court").getLocalBounds().height);
	// Adjust Position
	RM->getSprite("basketball_court").setPosition(RM->getSprite("basketball_court").getPosition().x, RM->getSprite("basketball_court").getPosition().y + 60);
}


void Basketball_Court::update(float delta)
{
	// Empty
}

void Basketball_Court::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball_court"));
}

sf::Sprite& Basketball_Court::getSprite()
{
	return RM->getSprite("basketball_court");
}