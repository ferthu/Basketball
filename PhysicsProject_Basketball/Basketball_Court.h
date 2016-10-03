#ifndef BASKETBALL_COURT_HPP
#define BASKETBALL_COURT_HPP

#include "Entity.h"

class Basketball_Court : public Entity
{
public:
	Basketball_Court(std::shared_ptr<ResourceManager> resource) : Entity(resource) {}
	
	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();
};
#endif