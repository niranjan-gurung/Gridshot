#pragma once
#include "./States/MainMenuState.h"

class Game
{
private:
	std::shared_ptr<sf::RenderWindow> gameWindow;	// main window
	std::stack<std::shared_ptr<State>> states;		// track states
	Util screenDimensions;							// screen width + height

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
		"Gridshot Clone!",
		sf::Style::Fullscreen
		);
	gameWindow->setFramerateLimit(60);
}

inline void Game::InitStates()
{
	// default state:
	states.push(std::make_unique<MainMenuState>(gameWindow, &states));
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
	std::cout << "gameWindow deallocation." << std::endl;

	while (!states.empty())
	{
		//delete states.top();
		states.pop();
	}
}
