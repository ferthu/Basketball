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

	sfg::Table::Ptr UITable;

	sfg::Label::Ptr velocityLabel;
	sfg::Entry::Ptr velocityXEntry;
	sfg::Entry::Ptr velocityYEntry;

	sfg::Label::Ptr angularVelocityLabel;
	sfg::Entry::Ptr angularVelocityEntry;

	sfg::Button::Ptr startButton;
	sfg::Button::Ptr resetButton;

	sfg::Box::Ptr UIBox;
	sfg::Box::Ptr buttonsBox;
};

#endif