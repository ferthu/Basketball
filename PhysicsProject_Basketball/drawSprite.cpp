#include "drawSprite.h"

void drawSprite::ss(sf::Sprite sprite)
{
	this->sprite = sprite;
}
void drawSprite::draw(sf::Sprite& sprite, sf::RenderWindow& drawWindow)
{
	drawWindow.draw(sprite);
}