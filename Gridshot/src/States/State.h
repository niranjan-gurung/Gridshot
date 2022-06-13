#pragma once

#include "../Util/Util.h"

#include <iomanip>
#include <stack>
#include <array>
#include <memory>

class State
{
protected:
	std::shared_ptr<sf::RenderWindow> window;
	sf::Event event;
	std::stack<std::shared_ptr<State>>* states;

public:
	State(
		std::shared_ptr<sf::RenderWindow> window, 
		std::stack<std::shared_ptr<State>>* states
	);
	virtual ~State();

	virtual void Update() = 0;
	virtual void Render() = 0;
};

inline State::State(
	std::shared_ptr<sf::RenderWindow> window, 
	std::stack<std::shared_ptr<State>>* states
) 
	: window(window), states(states) 
{}

inline State::~State() 
{ 
	std::cout << "State Destructor" << std::endl; 
}