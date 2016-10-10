#include "Basketball.h"
#include "VectorFunctions.h"
#include <cmath>
#include <iostream>
Basketball::Basketball(std::shared_ptr<ResourceManager> resource, float pixelsPerMeter) : Entity(resource)
{
	radius = 0.2426f; 
	weight = 0.62369f;

	angularVelocity = 0.0f;
	angle = 0.0f;

	active = false;

	this->pixelsPerMeter = pixelsPerMeter;

	basePosition = sf::Vector2f(170.0f, 385.0f);
	position = basePosition;
	velocity = sf::Vector2f(0.0f, 0.0f);
}

void Basketball::initialize(int screenWidth, int screenHeight)
{
	RM->spriteCache.defaultSpriteSetup("basketball", "Sprites/basketball.png");

	sf::Vector2u textureSize = RM->getSprite("basketball").getTexture()->getSize();

	RM->getSprite("basketball").setScale(radius * 2.0f * pixelsPerMeter / textureSize.x, radius * 2.0f * pixelsPerMeter / textureSize.y);

	RM->getSprite("basketball").setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);

	

	
}
void Basketball::update(float delta)
{
	
	if (active)
	{
		velocity += sf::Vector2f(0.0f, 9.82f) * delta;

		position += velocity * delta * pixelsPerMeter;
		angle += angularVelocity * delta;

		while (angle > 6.28318530718f)
			angle -= 6.28318530718f;
		while (angle < 0)
			angle += 6.28318530718f;
	}

	// Final Position of the ball
	RM->getSprite("basketball").setPosition(position);
	// Position Of The Ball's collision circle.
	setCircleShape(sf::Vector2f(RM->getSprite("basketball").getPosition().x - 25
		, RM->getSprite("basketball").getPosition().y - 25), 24.6, sf::Color::Black);
	// Final Rotation of the ball.
	RM->getSprite("basketball").setRotation(-angle / 6.28318530718f * 360.0f);
}

void Basketball::draw(sf::RenderWindow& window)
{
	window.draw(RM->getSprite("basketball"));
	//window.draw(CircleCollisionBall);
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
float Basketball::getRadius()
{
	return radius;
}
void Basketball::setRadius(const float& radius)
{
	this->radius = radius;
}

void Basketball::handleCollision(sf::Vector2f otherCollisionNormal, float otherCollisionPlaneDistance, float e, float delta)
{
	float positionAlongNormal = dot(otherCollisionNormal, position);
	float velocityAlongNormal = dot(otherCollisionNormal, velocity);
	float collisionDistance = radius * pixelsPerMeter - otherCollisionPlaneDistance;

	// collision
	if (positionAlongNormal <= collisionDistance && velocityAlongNormal < 0)
	{
		// move out of wall
		position = position + otherCollisionNormal * (collisionDistance - positionAlongNormal);
		
		// find surface direction
		sf::Vector2f surfaceDirection = -v3tov2(cross(v2tov3(otherCollisionNormal), sf::Vector3f(0.0f,0.0f,1.0f)));

		sf::Vector2f newVelocity = (((1 - (2.0f / 5.0f) * e) * dot(surfaceDirection, velocity) + (2.0f / 5.0f) * (1.0f + e) * radius * -angularVelocity) / (1.0f + 2.0f / 5.0f)) * surfaceDirection - e * dot(velocity, otherCollisionNormal) * otherCollisionNormal;
		angularVelocity = -((1.0f + e) * dot(surfaceDirection, velocity) + (2.0f / 5.0f - e) * radius * -angularVelocity) / (radius * (1.0f + 2.0f / 5.0f));
		velocity = newVelocity;
	}

}

void Basketball::setCircleShape(sf::Vector2f position, float radius, sf::Color color)
{
	CircleCollisionBall.setPosition(position);
	CircleCollisionBall.setRadius(radius);
	CircleCollisionBall.setFillColor(color);
}

