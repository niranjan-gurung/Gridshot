#pragma once

#include "State.h"

class PauseState : public State
{
private:
	Util util;
	sf::Text tGamePaused;

public:
	PauseState(
		std::shared_ptr<sf::RenderWindow> window, 
		std::stack<std::shared_ptr<State>>* states
	);

	~PauseState();

	static bool unpaused;
	//static bool IsUnpaused();

	void Update() override;
	void Render() override;
};
