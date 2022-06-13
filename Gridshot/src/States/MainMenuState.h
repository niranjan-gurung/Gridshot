#pragma once

#include "GameplayState.h"

class MainMenuState : public State
{
private:
	Util fontUtil;
	sf::Text tStartText;

public:
	MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::shared_ptr<State>>* states);
	~MainMenuState();

	void Update() override;
	void Render() override;
};
