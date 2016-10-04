#include "UI.h"

UI::UI(Basketball* ball)
{
	this->ball = ball;

	UIWindow = sfg::Window::Create();
	UIWindow->SetTitle("Basketball UI");

	UIBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);

	startButton = sfg::Button::Create("Start");
	startButton->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&UI::StartBall, this));

	resetButton = sfg::Button::Create("Reset");
	resetButton->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&UI::ResetBall, this));

	UIBox->Pack(startButton);
	UIBox->Pack(resetButton);

	UIWindow->Add(UIBox);
}

void UI::Update(float delta)
{
	UIWindow->Update(delta);
}

void UI::Draw(sf::RenderWindow& window)
{
	sfgui.Display(window);
}

void UI::HandleEvents(const sf::Event& event)
{
	UIWindow->HandleEvent(event);
}

void UI::ResetBall()
{
	if (ball->getActive())
	{
		ball->setPosition(ball->getBasePosition());
		ball->setActive(false);
	}
}

void UI::StartBall()
{
	ball->setActive(true);
}