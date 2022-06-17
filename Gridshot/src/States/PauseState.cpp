#include "PauseState.h"

bool PauseState::unpaused = false;

PauseState::PauseState(
	std::shared_ptr<sf::RenderWindow> window,
	std::stack<std::shared_ptr<State>>* states
) 
	: State(window, states)//, unpaused(false)
{
	std::cout << "Entered pause constructor." << std::endl;

    util.SetupText(tGamePaused, "Game is paused, press esc to continue!");
}

PauseState::~PauseState() {}

//bool PauseState::IsUnpaused() 
//{ 
//    return unpaused; 
//}

void PauseState::Update()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

        case sf::Event::KeyPressed:
            // press Esc to unpause and continue game
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "Game continued!" << std::endl;
                unpaused = true;
            }  
            break;
        }
    }

    if (unpaused)
    {
        states->pop();
    }
}
 
void PauseState::Render()
{
    std::cout << "Entered pause render" << std::endl;
    window->draw(tGamePaused);
}