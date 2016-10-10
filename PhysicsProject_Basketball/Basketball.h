#ifndef BASKETBALL_HPP
#define BASKETBALL_HPP

#include "Entity.h"

class Basketball_hoop;

class Basketball : public Entity
{
public:
	Basketball(std::shared_ptr<ResourceManager> resource, float pixelsPerMeter);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite();

	float getAngle();
	void setAngle(const float& angle);
	float getRadius();
	void setRadius(const float& radius);
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

	void handleCollision(sf::Vector2f otherCollisionNormal, float otherCollisionPlaneDistance, float e, float delta);
	void setCircleShape(sf::Vector2f position, float radius, sf::Color color);

	// Circle Based Collision
	sf::CircleShape CircleCollisionBall;
	
private:
	Basketball() {}

	// in meters
	float radius;
	// in kilograms
	float weight;
	// in rad/s counterclockwise
	float angularVelocity;
	// in rad, counterclockwise
	float angle;
	// turns physics on/off
	bool active;

	// start position of ball
	sf::Vector2f basePosition;
	sf::Vector2f position;
	sf::Vector2f velocity;

	float pixelsPerMeter;
};
#endif
