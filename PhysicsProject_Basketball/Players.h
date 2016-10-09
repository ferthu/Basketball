#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "Entity.h"

#include "Basketball.h"

class Players : public Entity
{
public:
	Players(std::shared_ptr<ResourceManager> resource, std::shared_ptr<Basketball> ball);

	void initialize(int screenWidth, int screenHeight);
	void update(float delta);
	void draw(sf::RenderWindow& window);
	sf::Sprite& getSprite() { sf::Sprite sprite; return sprite; }

	bool getActive();
	void setActive(bool active);

	
private:
	int playerTurn;
	bool active;
	bool reset; // True if the reset button was hit. Then it goes back to false.
	std::shared_ptr<Basketball> ball;
	sf::Vector2f basePosition;
	
};
#endif
