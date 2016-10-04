#ifndef UI_H
#define UI_H

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

#include "Basketball.h"

class UI
{
public:
	UI(Basketball* ball);

	void HandleEvents(const sf::Event& event);

	void Update(float delta);
	void Draw(sf::RenderWindow& window);
	//~UI();
private:
	UI();

	void ResetBall();
	void StartBall();

	Basketball* ball;

	sfg::SFGUI sfgui;

	sfg::Window::Ptr UIWindow;

	sfg::Button::Ptr startButton;
	sfg::Button::Ptr resetButton;

	sfg::Box::Ptr UIBox;
};

#endif