#ifndef BASKETBALL_HOOP_HPP
#define BASKETBALL_HOOP_HPP

#include "Entity.h"
#include "Game.h"

class Basketball_hoop : public Entity
{
public:

	Basketball_hoop(std::shared_ptr<ResourceManager> resource);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	sf::Sprite& getSprite();

	void setRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	// Rectangle Based Collision for the basket
	sf::RectangleShape basketCollisionRect;

	float pixelsPerMeter;
private:

	
};
#endif
