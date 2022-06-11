#include "MainMenuState.h"

MainMenuState::MainMenuState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states) 
	: State(window, states)
{
	// load and setup the menu text:
	fontUtil.SetupText(tStartText, "Click to Start!");
}

MainMenuState::~MainMenuState() {}

void MainMenuState::Update() 
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

			// Process target being clicked:
		case sf::Event::MouseButtonPressed: 
			// initial 'click to start' text state:
			if (tStartText.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) 
			{
				std::cout << "Start text clicked!" << std::endl;

				// remove the start text from screen:
				tStartText.setString("");
				// load the game state onto the stack:
				states->push(new GameplayState(window, states));
			}
			break;
		}
	}
}

void MainMenuState::Render() 
{
	window->draw(tStartText);
}

void MainMenuState::EndState() {}