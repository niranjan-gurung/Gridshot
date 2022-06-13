#pragma once

#include "State.h"
#include "../Util/Stats.h"

class GameoverState : public State
{
private:
	std::shared_ptr<Stats> localStats;
	
	// utility for font rendering:
	Util util;
	sf::Text tEndText, tExitText, tRestartGameText, 
		tScore, tHit, tMiss, tAccuracy;

public:
	GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<std::shared_ptr<State>>* states, std::shared_ptr<Stats> stats);
	~GameoverState();

	void displayStatSummary();

	void Update() override;
	void Render() override;
};