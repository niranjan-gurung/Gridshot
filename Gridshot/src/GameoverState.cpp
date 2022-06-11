#include "GameoverState.h"
#include "GameplayState.h"

GameoverState::GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states, std::shared_ptr<Stats> stats)
    : State(window, states), localStats(stats)
{
    std::cout << "inside the gameover state constructor!" << std::endl;
    
    stats = nullptr;    // don't need this as 'localStats' now has its values
    
    displayStatSummary();
}

GameoverState::~GameoverState()
{

}

void GameoverState::displayStatSummary()
{
    std::cout << "score: " << localStats->score << std::endl;
    std::cout << "hitcounter: " << localStats->hitCounter << std::endl;
    std::cout << "misscounter: " << localStats->missCounter << std::endl;
    std::cout << "accuracy: " << localStats->accuracy << std::endl;
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