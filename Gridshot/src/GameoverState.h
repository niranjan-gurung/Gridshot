#pragma once

#include "State.h"
#include "Stats.h"

class GameoverState : public State
{
private:
	std::shared_ptr<Stats> localStats;

public:
	GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states, std::shared_ptr<Stats> stats);
	~GameoverState();

	void displayStatSummary();

	void Update() override;
	void Render() override;
	void EndState() override;
};