#include "loadSprite.h"

#include <iostream>

sf::Sprite& loadSprite::defaultSpriteLoad(const std::string name, const std::string path)
{
	_texture[name] = sf::Texture();
	if (!_texture[name].loadFromFile(path))
	{
		std::cout << "Error Loading Image From Path: " << path << std::endl;
		successfulSpriteCreation = false;
	}
	else
	{
		sprite.setTexture(_texture[name]);
		successfulSpriteCreation = true;
	}

	return this->sprite;
}

sf::Sprite loadSprite::loadSpriteRect(const std::string name, std::string path, sf::IntRect rect)
{
	_texture[name] = sf::Texture();
	if (!_texture[name].loadFromFile(path, rect))
	{
		std::cout << "Error Loading Image From Path: " << path << std::endl;
		successfulSpriteCreation = false;
	}
	else
	{
		sprite.setTexture(_texture[name]);
		successfulSpriteCreation = true;
	}
	
	return this->sprite;
}