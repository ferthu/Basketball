#include "Basketball.h"

Basketball::Basketball(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{
	circumference = 74.93; 
	weight = 623.67;
}

void Basketball::initialize(int screenWidth, int screenHeight)
{
	RM->spriteCache.defaultSpriteSetup("basketball", "Sprites/basketball.png");
	RM->getSprite("basketball").setScale(1, 1);
	
}
void Basketball::update(float delta)
{

}

void Basketball::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball"));
}

sf::Sprite& Basketball::getSprite()
{
	return RM->getSprite("basketball");
}