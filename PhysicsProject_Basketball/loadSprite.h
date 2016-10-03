#ifndef LOADSPRITE_HPP
#define LOADSPRITE_HPP

// SFML
#include <SFML\graphics.hpp>

#include <string>
#include <map>

class loadSprite
{
public:
	loadSprite() {}

	sf::Sprite& defaultSpriteLoad(const std::string name, const std::string path);
	sf::Sprite loadSpriteRect(const std::string name, const std::string path, sf::IntRect rect);


private:
	std::map<std::string, sf::Texture> _texture;
	sf::Sprite sprite;

	bool successfulSpriteCreation;

};
#endif
