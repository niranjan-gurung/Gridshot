#pragma once

#include "GameoverState.h"
#include "../Util/Random.h"

class GameplayState : public State
{
private:
	static const int MAX_TARGETS = 3;
	static const int TIME_LIMIT = 60;

	std::array<sf::CircleShape, MAX_TARGETS> targets;	// targets

	// random number generator for the spawn locations of the targets:
	Random rand;

	// boolean to track state changes:
	bool targetHit;

	// stats:
	std::shared_ptr<Stats> stats;

	Util util;
	// all game texts:
	sf::Text tTimer, tScore, tAccuracy;

	// start timer:
	sf::Clock clock;
	int tElapsedTime;

private:
	// initial targets setup:
	void InitTargets(std::array<sf::CircleShape, MAX_TARGETS>& targets);
	void PreventOverlap(int& i, std::array<sf::CircleShape, MAX_TARGETS>& targets);
	void TargetCleanup(std::array<sf::CircleShape, MAX_TARGETS>& targets);

public:
	GameplayState(
		std::shared_ptr<sf::RenderWindow> window, 
		std::stack<std::shared_ptr<State>>* states
	);
	~GameplayState();

	void Update() override;
	void Render() override;
};
