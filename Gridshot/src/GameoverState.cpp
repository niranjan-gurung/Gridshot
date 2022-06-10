#include "GameoverState.h"
#include "GameplayState.h"

GameoverState::GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states)
    : State(window, states)//, b(nullptr)
{
    std::cout << "inside the gameover state constructor!" << std::endl;

    //b = s;

    displayStatSummary();
}

GameoverState::~GameoverState()
{

}

void GameoverState::displayStatSummary()
{
    /*std::cout << (*a).getStats()->score << std::endl;
    std::cout << (*a).getStats()->hitCounter << std::endl;
    std::cout << (*a).getStats()->missCounter << std::endl;
    std::cout << (*a).getStats()->accuracy << std::endl;*/

    /*std::cout << b->getStats().score << std::endl;
    std::cout << b->getStats().hitCounter << std::endl;
    std::cout << b->getStats().missCounter << std::endl;
    std::cout << b->getStats().accuracy << std::endl;*/

    /*std::cout << (*b).getStats()->score << std::endl;
    std::cout << (*b).getStats()->hitCounter << std::endl;
    std::cout << (*b).getStats()->missCounter << std::endl;
    std::cout << (*b).getStats()->accuracy << std::endl;*/
}

void GameoverState::Update()
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

            break;

        case sf::Event::KeyPressed:
            // press space to restart game loop
            if (event.key.code == sf::Keyboard::Space)
            {
                std::cout << "Game Restarted!" << std::endl;
                //tEndText.setString("");
                //tStartText.setString("Click to Start!");

                //paused = false;
                //targetInit = false;
                //targetHit = false;

                // reset counters for each restart.
                /*hitCounter = 0;
                missedCounter = 0;
                score = 0;
                accuracy = 100;*/

                //clock.restart();
            }
            // press Esc to close game
            if (event.key.code == sf::Keyboard::Escape)
            {
                std::cout << "Game Closed!" << std::endl;
                window->close();
            }
            break;
        }

    }
}

void GameoverState::Render()
{

}

void GameoverState::EndState() {}