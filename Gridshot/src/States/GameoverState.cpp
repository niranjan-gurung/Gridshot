#include "GameoverState.h"

GameoverState::GameoverState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states, std::shared_ptr<Stats> stats)
    : State(window, states), localStats(stats)
{
    std::cout << "inside the gameover state constructor!" << std::endl;
    
    stats = nullptr;    // don't need this as 'localStats' now has its values
    
    // game summary setup:
    util.SetupText(tEndText, "Time Up!");
    util.SetupText(tExitText, "Press Esc to close game!");
    util.SetupText(tRestartGameText, "Press Space to restart game!");
    util.SetupText(tScore, "Score: " + std::to_string(localStats->score));
    util.SetupText(tHit, "Targets hit: " + std::to_string(localStats->hitCounter));
    util.SetupText(tMiss, "Targets missed: " + std::to_string(localStats->missCounter));
    util.SetupText(tAccuracy, "Accuracy: " + std::to_string(localStats->accuracy) + "%");

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

    // game summary text position setup:
    tRestartGameText.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+20);
    tExitText.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+40);
    tScore.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+80);
    tHit.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+100);
    tMiss.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+120);
    tAccuracy.setPosition(static_cast<float>(util.GetScreenWidth())/2, static_cast<float>(util.GetScreenHeight()/2)+140);
}

void GameoverState::Render()
{
    // game summary display:
    window->draw(tEndText);
    window->draw(tRestartGameText);
    window->draw(tExitText);
    window->draw(tScore);
    window->draw(tHit);
    window->draw(tMiss);
    window->draw(tAccuracy);
}

void GameoverState::EndState() {}