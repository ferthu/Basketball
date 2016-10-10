#include "Basketball_hoop.h"
#include <math.h>
#include <iostream>


Basketball_hoop::Basketball_hoop(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{

}

void Basketball_hoop::initialize(int screenWidth, int screenHeight)
{
	// Load Sprite
	RM->spriteCache.defaultSpriteSetup("basketball_hoop", "Sprites/hoop.png");
	// Scale The Image
	float hoopHeightInMeters = 544.0f / 440.0f * 3.048f;
	sf::Vector2u textureSize = RM->getSprite("basketball_hoop").getTexture()->getSize();
	RM->getSprite("basketball_hoop").setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	float size = hoopHeightInMeters * pixelsPerMeter / textureSize.x / 2.0f;
	RM->getSprite("basketball_hoop").setScale(size, size);

	// pos of left hoop edge: hoopTexturePosition + (4, 104) * size
	// pos of right hoop edge: hoopTexturePosition + (70, 104) * size
	// pos of top of plank: hoopTexturePosition + (87, 3) * size
	// pos of bottom of plank: hoopTexturePosition + (87, 120) * size

	// Adjust Position
	RM->getSprite("basketball_hoop").setPosition(screenWidth - size * textureSize.x, 
		screenHeight - size * textureSize.y);
	RM->getSprite("basketball_hoop").setPosition(0, 0);
}

void Basketball_hoop::update(float delta)
{
	setRectangleShape(sf::Vector2f(932.5, 215), sf::Vector2f(5.0f, 100.5f), sf::Color::Red);
}

void Basketball_hoop::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball_hoop"));
	//window.draw(basketCollisionRect);
}

sf::Sprite& Basketball_hoop::getSprite()
{
	return RM->getSprite("basketball_hoop");
}

void Basketball_hoop::setRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
	basketCollisionRect.setPosition(position);
	basketCollisionRect.setSize(size);
	basketCollisionRect.setFillColor(color);
}
