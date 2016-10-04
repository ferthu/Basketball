#ifndef BASKETBALL_HPP
#define BASKETBALL_HPP

#include "Entity.h"

class Basketball : public Entity
{
public:
	Basketball(std::shared_ptr<ResourceManager> resource);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();

	float getAngluarVelocity();
	void setAngularVelocity(const float& angularVelocity);
	bool getActive();
	void setActive(bool active);
	sf::Vector2f getBasePosition();
	void setBasePosition(const sf::Vector2f& basePosition);
	sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getVelocity();
	void setVelocity(const sf::Vector2f& velocity);

private:
	Basketball() {}

	// in meters
	float radius;
	// in kilograms
	float weight;
	// in rad/s counterclockwise
	float angularVelocity;
	// turns physics on/off
	bool active;

	// start position of ball
	sf::Vector2f basePosition;
	sf::Vector2f position;
	sf::Vector2f velocity;
};
#endif
