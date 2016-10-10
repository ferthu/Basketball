#ifndef BASKETBALL_HOOP_HPP
#define BASKETBALL_HOOP_HPP

#include "Entity.h"
#include "CollisionObject.h"
class Basketball_hoop : public Entity, public CollisionObject
{
public:

	Basketball_hoop(std::shared_ptr<ResourceManager> resource);

	Basketball_hoop(std::shared_ptr<ResourceManager> resource) : Entity(resource) {}

	Basketball_hoop(sf::Vector2f normal, float distance, float e);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	sf::Sprite& getSprite();



	void setRectangleShape(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	// Rectangle Based Collision for the basket
	sf::RectangleShape basketCollisionRect;

	void checkBallCollision(Basketball& ball, float pixelsPerMeter, float delta);



private:
	sf::Vector2f normal;
	float distance;
	float e;
	
};
#endif
