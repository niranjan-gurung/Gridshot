#pragma once

#include "Util.h"

#include <iomanip>
#include <stack>
#include <array>
#include <random>
#include <memory>

class State
{
protected:
	std::shared_ptr<sf::RenderWindow> window;
	sf::Event event;
	std::stack<State*>* states;

public:
	State(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states);
	~State();

	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void EndState() = 0;
};

inline State::State(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states) 
	: window(window), states(states) {}

inline State::~State() {}