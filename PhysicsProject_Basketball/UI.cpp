#include "UI.h"
#include <string>

UI::UI(std::shared_ptr<Basketball> ball)
{
	this->ball = ball;

	UIWindow = sfg::Window::Create();
	UIWindow->SetTitle("Basketball UI");

	UIBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 5.0f);

	velocityLabel = sfg::Label::Create("Velocity (X, Y): ");
	velocityXEntry = sfg::Entry::Create();
	velocityYEntry = sfg::Entry::Create();

	angularVelocityLabel = sfg::Label::Create("Angular Velocity (rad/s): ");
	angularVelocityEntry = sfg::Entry::Create("");

	startButton = sfg::Button::Create("Start");
	startButton->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&UI::StartBall, this));
	resetButton = sfg::Button::Create("Reset");
	resetButton->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind(&UI::ResetBall, this));

	UITable = sfg::Table::Create();
	UITable->Attach(velocityLabel, sf::Rect<sf::Uint32>(0, 0, 1, 1), sfg::Table::FILL, sfg::Table::FILL);
	UITable->Attach(velocityXEntry, sf::Rect<sf::Uint32>(1, 0, 1, 1));
	UITable->Attach(velocityYEntry, sf::Rect<sf::Uint32>(2, 0, 1, 1));

	UITable->Attach(angularVelocityLabel, sf::Rect<sf::Uint32>(0, 1, 1, 1), sfg::Table::FILL, sfg::Table::FILL);
	UITable->Attach(angularVelocityEntry, sf::Rect<sf::Uint32>(1, 1, 1, 1));

	buttonsBox = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 5.0f);
	buttonsBox->Pack(resetButton);
	buttonsBox->Pack(startButton);

	UITable->SetColumnSpacings(5.0f);
	UITable->SetRowSpacings(5.0f);

	UIBox->Pack(UITable);
	UIBox->Pack(buttonsBox);

	UIWindow->Add(UIBox);

	UIWindow->SetPosition(sf::Vector2f(10.0f, 10.0f));
	UIWindow->SetRequisition(sf::Vector2f(300.0f, 130.0f));
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
		ball->setFail(false);
		ball->setPosition(ball->getBasePosition());
		ball->setActive(false);
		ball->setAngle(0.0f);
	}
}

void UI::StartBall()
{
	if (!ball->getActive())
	{
		ball->setActive(true);

		ball->setVelocity(sf::Vector2f(std::stof(velocityXEntry->GetText().toAnsiString()), -std::stof(velocityYEntry->GetText().toAnsiString())));

		ball->setAngularVelocity(std::stof(angularVelocityEntry->GetText().toAnsiString()));
	}
}