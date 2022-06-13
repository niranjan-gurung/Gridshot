#pragma once

#include "GameplayState.h"

class MainMenuState : public State
{
private:
	Util util;
	sf::Text tStartText;
	sf::Text tWelcometext;

public:
	MainMenuState(
		std::shared_ptr<sf::RenderWindow> window, 
		std::stack<std::shared_ptr<State>>* states
	);
	~MainMenuState();

	void Update() override;
	void Render() override;
};
