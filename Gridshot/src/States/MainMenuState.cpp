#include "MainMenuState.h"

MainMenuState::MainMenuState(
	std::shared_ptr<sf::RenderWindow> window, 
	std::stack<std::shared_ptr<State>>* states
) 
	: State(window, states)
{
	// load and setup the menu text:
	util.SetupText(tStartText, "Click to Start!");
	util.SetupText(tWelcometext, "Welcome To Gridshot!");
}

MainMenuState::~MainMenuState() 
{ 
	std::cout << "menu state destructor" << std::endl; 
}

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
				states->push(std::make_unique<GameplayState>(window, states));
			}
			break;
		}
	}

	tWelcometext.setPosition(
		static_cast<float>(util.GetScreenWidth())/2, 
		(static_cast<float>(util.GetScreenHeight())/2)-50);
}

void MainMenuState::Render() 
{
	window->draw(tWelcometext);
	window->draw(tStartText);
}
