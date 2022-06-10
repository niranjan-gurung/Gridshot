#pragma once

#include "State.h"

class GameplayState;

class GameoverState : public State
{
private:
	//std::shared_ptr<GameplayState> a;
	//GameplayState* b;

public:
	GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states);
	~GameoverState();

	void displayStatSummary();

	void Update() override;
	void Render() override;
	void EndState() override;
};