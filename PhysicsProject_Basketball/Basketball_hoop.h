#ifndef BASKETBALL_HOOP_HPP
#define BASKETBALL_HOOP_HPP

#include "Entity.h"

class Basketball_hoop : public Entity
{
public:
	Basketball_hoop(std::shared_ptr<ResourceManager> resource) : Entity(resource) {}
	
	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();

	
};
#endif
