#ifndef DRAWSPRITE_HPP
#define DRAWSPRITE_HPP

// SFML
#include <SFML\graphics.hpp>	
class drawSprite
{
public:
	drawSprite(){}
	
	void draw(sf::Sprite& sprite, sf::RenderWindow& drawWindow);
	void ss(sf::Sprite sprite);
private:
//	sf::RenderWindow drawWindow;
	sf::Sprite sprite;
};
#endif
