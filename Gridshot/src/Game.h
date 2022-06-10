#pragma once
#include "MainMenuState.h"

class Game
{
private:
	std::shared_ptr<sf::RenderWindow> gameWindow;	// main window
	std::stack<State*> states;						// track states
	Util screenDimensions;							// screen width + height

													// all game texts:
													/*sf::Text tStartText, tTimer, tEndText, 
													tExitText, tRestartGameText, tScore, 
													tHit, tMiss, tAccuracy;*/

private:
	void InitGameWindow();
	void InitStates();

public:
	Game();
	~Game();

	void Start();
	void Update();
	void Render();
};

inline void Game::InitGameWindow()
{
	gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(
		screenDimensions.GetScreenWidth(), 
		screenDimensions.GetScreenHeight()), 
		"Gridshot Clone!"
		);
	gameWindow->setFramerateLimit(60);
}

inline void Game::InitStates()
{
	// default state:
	states.push(new MainMenuState(this->gameWindow, &this->states));
}

inline void Game::Start()
{
	while (gameWindow->isOpen())
	{
		Update();
		Render();
	}
}

inline Game::~Game() 
{ 
	// gameWindow deallocation;
	std::cout << "shared_ptr destroyed." << std::endl;

	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}
