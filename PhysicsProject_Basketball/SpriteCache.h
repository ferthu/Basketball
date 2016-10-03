#ifndef SPRITECACHE_HPP
#define SPRITECACHE_HPP

#include <string>
#include <map>

#include "drawSprite.h"
#include "loadSprite.h"
#include <memory>
class SpriteCache
{
public:
	SpriteCache() { _loadSprite = std::make_shared<loadSprite>(); }

	void setupSpriteRect(const std::string spriteName, const std::string path, sf::IntRect rect);
	void defaultSpriteSetup(const std::string spriteName, const std::string path);
	sf::Sprite& getSprite(const std::string spriteName);
	
private:
	std::map<std::string, sf::Sprite> sprites;

	sf::Sprite sprite;
	// Used To Load The Sprite.
	std::shared_ptr<loadSprite> _loadSprite;
};
#endif
