#pragma once

#include "GameoverState.h"

// random number generator for the spawn locations of the targets:
static std::random_device dev;
static std::mt19937 rng(dev());
static std::uniform_int_distribution<std::mt19937::result_type> width(100, 600); 
static std::uniform_int_distribution<std::mt19937::result_type> height(100, 400);

class GameplayState : public State
{
private:
	static const int MAX_TARGETS = 3;
	static const int TIME_LIMIT = 5;

	std::array<sf::CircleShape, MAX_TARGETS> targets;	// targets

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
	GameplayState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states);
	~GameplayState();

	void Update() override;
	void Render() override;
	void EndState() override;
};
