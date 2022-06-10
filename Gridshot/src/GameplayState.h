#pragma once

#include "GameoverState.h"

// random number generator for the spawn locations of the targets:
static std::random_device dev;
static std::mt19937 rng(dev());
static std::uniform_int_distribution<std::mt19937::result_type> width(100, 600); 
static std::uniform_int_distribution<std::mt19937::result_type> height(100, 400);

//struct Stats;

//struct Stats
//{
//	int score, accuracy, hitCounter, missCounter;
//};

class GameplayState : public State
{
private:
	static const int MAX_TARGETS = 3;
	static const int TIME_LIMIT = 5;

	std::array<sf::CircleShape, MAX_TARGETS> targets;	// targets

														// boolean to track state changes:
	bool targetHit, targetInit, paused, menuTimerThresholdPassed;

	// stats:
	int score, accuracy, hitCounter, missCounter;
	//Stats stats;
	//std::shared_ptr<Stats> stats;
	//Stats* stats;

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

	//Stats* getStats() const;
	/*int getScore() const;
	int getHitCounter() const;
	int getMissCounter() const;
	int getAccuracy() const;*/

	/*void setScore(int value = 0);
	void setHitCounter(int value = 0);
	void setMissCounter(int value = 0);
	void setAccuracy(int value = 100);*/

	void Update() override;
	void Render() override;
	void EndState() override;
};

//inline Stats* GameplayState::getStats()		const { return stats; }

//inline int GameplayState::getScore()		const { return stats->score; }
//inline int GameplayState::getHitCounter()	const { return stats->hitCounter; }
//inline int GameplayState::getMissCounter()	const { return stats->missCounter; }
//inline int GameplayState::getAccuracy()		const { return stats->accuracy; }

//inline void GameplayState::setScore(int value = 0) { score = value; }
//inline void GameplayState::setHitCounter(int value = 0) { hitCounter = value; }
//inline void GameplayState::setMissCounter(int value = 0) { missCounter = value; }
//inline void GameplayState::setAccuracy(int value = 100) {accuracy = value; }
