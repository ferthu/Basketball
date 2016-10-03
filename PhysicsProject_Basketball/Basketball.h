#ifndef BASKETBALL_HPP
#define BASKETBALL_HPP

#include "Entity.h"

class Basketball : public Entity
{
public:
	Basketball(){ }
	Basketball(std::shared_ptr<ResourceManager> resource);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();

private:
	// In Centimeters.
	float circumference;
	// In Grams.
	float weight;

};
#endif
