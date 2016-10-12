#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

#include <SFML\graphics.hpp>
#include <math.h>

sf::Vector2f normalize(const sf::Vector2f& vector);

sf::Vector3f normalize(const sf::Vector3f& vector);

float dot(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

sf::Vector3f cross(const sf::Vector2f& vector1, const sf::Vector2f& vector2);

sf::Vector3f cross(const sf::Vector3f& vector1, const sf::Vector3f& vector2);

sf::Vector2f v3tov2(const sf::Vector3f& vector);

sf::Vector3f v2tov3(const sf::Vector2f& vector);

float length(const sf::Vector2f& vector);

float length2(const sf::Vector2f& vector);

#endif