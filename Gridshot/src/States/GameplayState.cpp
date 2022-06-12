#include "GameplayState.h"

GameplayState::GameplayState(std::shared_ptr<sf::RenderWindow> window, std::stack<State*>* states)
    : State(window, states), targetHit(false)
{
    // Heap init Stats object and update its values during gameplay.
    // This object will get passed into and printed in the gameoverstate as a summary:
    stats = std::make_unique<Stats>();

    tElapsedTime = 0;

    InitTargets(targets);
    std::cout << "target initialised\n";

    util.SetupText(tTimer, "");                                                         // timer text
    util.SetupText(tScore, "Score: " + std::to_string(stats->score));                   // score text
    util.SetupText(tAccuracy, "Accuracy: " + std::to_string(stats->accuracy) + "%");    // accuracy text
}

GameplayState::~GameplayState() 
{
    std::cout << "gamplay state destructor" << std::endl;
    TargetCleanup(targets);
}

void GameplayState::Update()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;

            // gameplay logic:
        case sf::Event::MouseButtonPressed: 
            for (int i = 0; i < MAX_TARGETS; i++) 
            {
                if (targets[i].getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) 
                {
                    stats->hitCounter++;
                    stats->score += 10;

                    // cap accuracy at 100%
                    if (stats->accuracy < 100)
                        stats->accuracy++;

                    targetHit = true;
                    targets[i].setPosition(width(rng), height(rng));

                    // prevent overlapping spawns
                    PreventOverlap(i, targets);
                    // if click hits one of the targets, then terminate out of loop early.
                    break;
                }
                else
                {
                    targetHit = false;  // if click misses the set of targets 
                }
            }
            // dont increment missed shots when clicking initial screen to proceed:
            if (!targetHit)
            {
                stats->missCounter++;
                stats->accuracy -= 1.5;  // if miss -> lower accuracy
            }
            break;
        }
    }

    // get current time:
    tElapsedTime = clock.getElapsedTime().asSeconds();
    // set text as current time:
    tTimer.setString(std::to_string(tElapsedTime));
    tTimer.setPosition(static_cast<float>(util.GetScreenWidth()) / 2, 5);     

    // score:
    tScore.setString("Score: " + std::to_string(stats->score));
    tScore.setPosition(static_cast<float>(util.GetScreenWidth()) - 200, 5);

    // accuracy:
    tAccuracy.setString("Accuracy: " + std::to_string(stats->accuracy) + "%");
    tAccuracy.setPosition(200, 5);

    // when gameplay timer runs out, enter the gameover state:
    if (tElapsedTime >= TIME_LIMIT)
    {
        std::cout << "Time Up!" << std::endl;
        states->push(new GameoverState(window, states, stats));
    }
}

void GameplayState::Render()
{
    // the targets
    for (auto& value : targets)
    {
        window->draw(value);
    }

    // on screen texts:
    window->draw(tTimer);
    window->draw(tScore);
    window->draw(tAccuracy);
}

void GameplayState::EndState() {}

// initial targets setup:
void GameplayState::InitTargets(std::array<sf::CircleShape, MAX_TARGETS>& targets) 
{
    for (int i = 0; i < MAX_TARGETS; i++) 
    {
        targets[i].setFillColor(sf::Color::Cyan);
        targets[i].setRadius(40.0f);
        targets[i].setPosition(width(rng), height(rng));

        // prevent overlapping spawns
        PreventOverlap(i, targets);
    }
}

// prevent overlapping spawns when generating new position for clicked targets:
void GameplayState::PreventOverlap(int& i, std::array<sf::CircleShape, MAX_TARGETS>& targets) 
{
    for (int j = 0; j < MAX_TARGETS; j++) 
    {
        while (i != j && targets[i].getGlobalBounds().intersects(targets[j].getGlobalBounds())) 
        {
            targets[i].setPosition(width(rng), height(rng));
            j = 0;
        }
    }
}

void GameplayState::TargetCleanup(std::array<sf::CircleShape, MAX_TARGETS>& targets) 
{
    for (int i = 0; i < targets.size(); i++)
    {
        targets[i].setRadius(0.0f);
    }
}