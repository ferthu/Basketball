#include "Basketball.h"

Basketball::Basketball(std::shared_ptr<ResourceManager> resource) : Entity(resource)
{
	radius = 0.2426f; 
	weight = 0.62369f;

	angularVelocity = 0.0f;
	angle = 0.0f;

	active = false;

	basePosition = sf::Vector2f(100.0f, 100.0f);
	position = basePosition;
	velocity = sf::Vector2f(0.0f, 0.0f);
}

void Basketball::initialize(int screenWidth, int screenHeight)
{
	RM->spriteCache.defaultSpriteSetup("basketball", "Sprites/basketball.png");
	RM->getSprite("basketball").setScale(radius, radius);
	
}
void Basketball::update(float delta)
{
	if (active)
	{
		position += velocity * delta;
	}
}

void Basketball::draw(sf::RenderWindow& window)
{
	RM->getSprite("basketball").setPosition(position);
	window.draw(RM->getSprite("basketball"));
}

sf::Sprite& Basketball::getSprite()
{
	return RM->getSprite("basketball");
}

float Basketball::getAngluarVelocity()
{
	return angularVelocity;
}
void Basketball::setAngularVelocity(const float& angularVelocity)
{
	this->angularVelocity = angularVelocity;
}
bool Basketball::getActive()
{
	return active;
}
void Basketball::setActive(bool active)
{
	this->active = active;
}
sf::Vector2f Basketball::getBasePosition()
{
	return basePosition;
}
void Basketball::setBasePosition(const sf::Vector2f& basePosition)
{
	this->basePosition = basePosition;
}
sf::Vector2f Basketball::getPosition()
{
	return position;
}
void Basketball::setPosition(const sf::Vector2f& position)
{
	this->position = position;
}
sf::Vector2f Basketball::getVelocity()
{
	return velocity;
}
void Basketball::setVelocity(const sf::Vector2f& velocity)
{
	this->velocity = velocity;
}
float Basketball::getAngle()
{
	return angle;
}
void Basketball::setAngle(const float& angle)
{
	this->angle = angle;
}