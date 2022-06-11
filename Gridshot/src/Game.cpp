#include "Game.h"

Game::Game() 
{
    InitGameWindow();
    InitStates();
}

void Game::Update()   
{
    if (!states.empty())
    {
        states.top()->Update();
    }
    else
    {
        gameWindow->close();
    }

    //sf::Event event;
    //while (gameWindow->pollEvent(event))
    //{
    //	switch (event.type)
    //	{
    //	// close window event:
    //	case sf::Event::Closed:
    //		gameWindow->close();
    //		std::cout << "Window closed!" << std::endl;
    //		break;

    //      // Process target being clicked:
    //      case sf::Event::MouseButtonPressed: 
    //          // initial 'click to start' text state:
    //          if (!targetInit && tStartText.getGlobalBounds().contains(gameWindow->mapPixelToCoords(sf::Mouse::getPosition(*gameWindow)))) 
    //          {
    //              InitTargets(targets);
    //              targetInit = true;
    //              std::cout << "target initialised\n";
    //              tStartText.setString("");
    //              clock.restart();
    //          } 
    //          // gameplay state:
    //          else    
    //          {
    //              for (int i = 0; i < MAX_TARGETS; i++) 
    //              {
    //                  if (targets[i].getGlobalBounds().contains(gameWindow->mapPixelToCoords(sf::Mouse::getPosition(*gameWindow)))) 
    //                  {
    //                      hitCounter++;
    //                      score += 10;
    //                              
    //                      // cap accuracy at 100%
    //                      if (accuracy < 100)
    //                          accuracy++;

    //                      targetHit = true;
    //                      targets[i].setPosition(width(rng), height(rng));
    //                                  
    //                      // prevent overlapping spawns
    //                      PreventOverlap(i, targets);
    //                      // if click hits one of the targets, then terminate out of loop early.
    //                      break;
    //                  }
    //                  else
    //                  {
    //                      targetHit = false;  // if click misses the set of targets 
    //                  }
    //              }
    //              // dont increment missed shots when clicking initial screen to proceed:
    //              if (!targetHit && targetInit)
    //              {
    //                  missedCounter++;
    //                  accuracy -= 1.5;         // if miss -> lower accuracy
    //              }
    //          }
    //          break;
    //          // mousePressed-event-end

    //      case sf::Event::KeyPressed:
    //          // press space to restart game loop
    //          if (event.key.code == sf::Keyboard::Space && paused)
    //          {
    //              std::cout << "Game Restarted!" << std::endl;
    //              tEndText.setString("");
    //              tStartText.setString("Click to Start!");

    //              paused = false;
    //              targetInit = false;
    //              targetHit = false;

    //              // reset counters for each restart.
    //              hitCounter = 0;
    //              missedCounter = 0;
    //              score = 0;
    //              accuracy = 100;
    //                       
    //              clock.restart();
    //          }
    //          // press Esc to close game
    //          if (event.key.code == sf::Keyboard::Escape && paused)
    //          {
    //              std::cout << "Game Closed!" << std::endl;
    //              gameWindow->close();
    //          }
    //          break;
    //       }
    //}
}

void Game::Render()
{
    // clear screen before drawing onto it:
    gameWindow->clear(sf::Color::White);
    if (!states.empty())
    {
        states.top()->Render();
    }
    gameWindow->display();

    // whilst game running... update and render everything:
    //if (!paused)
    //{
    //    // the targets
    //    for (auto& value : targets)
    //    {
    //        gameWindow->draw(value);
    //    }
    //    gameWindow->draw(tStartText);

    //    // final timer:
    //    //tElapsedTime = clock.getElapsedTime().asSeconds();
    //    //std::cout << std::fixed << std::setprecision(2) << "Elapsed time: " << tElapsedTime << std::endl;

    //    // on screen timer:
    //    //tTimer.setString(std::to_string(tElapsedTime));  // set text as the current time
    //    tTimer.setPosition(WIDTH/2, 5);        

    //    // score:
    //    tScore.setString("Score: " + std::to_string(score));
    //    tScore.setPosition(WIDTH-200, 5);

    //    // accuracy:
    //    tAccuracy.setString("Accuracy: " + std::to_string(accuracy) + "%");
    //    tAccuracy.setPosition(200, 5);     

    //    // once game has started, display the timer + score:
    //    if (targetInit)
    //    {
    //        gameWindow->draw(tTimer);
    //        gameWindow->draw(tScore);
    //        gameWindow->draw(tAccuracy);
    //    }
    //}
    //// if paused flag true, then cleanup targets, prompt 'time up' text and wait for user input:
    //else
    //{
    //    TargetCleanup(targets);

    //    // game summary setup and display:
    //    tEndText.setString("Time Up!");
    //    tHit.setString("Targets hit: " + std::to_string(hitCounter));
    //    tMiss.setString("Targets missed: " + std::to_string(missedCounter));
    //    
    //    tRestartGameText.setPosition(WIDTH/2, (HEIGHT/2)+20);
    //    tExitText.setPosition(WIDTH/2, (HEIGHT/2)+40);
    //    tScore.setPosition(WIDTH/2, (HEIGHT/2)+80);
    //    tHit.setPosition(WIDTH/2, (HEIGHT/2)+100);
    //    tMiss.setPosition(WIDTH/2, (HEIGHT/2)+120);
    //    tAccuracy.setPosition(WIDTH/2, (HEIGHT/2)+140);

    //    gameWindow->draw(tEndText);
    //    gameWindow->draw(tRestartGameText);
    //    gameWindow->draw(tExitText);
    //    gameWindow->draw(tScore);
    //    gameWindow->draw(tHit);
    //    gameWindow->draw(tMiss);
    //    gameWindow->draw(tAccuracy);
    //}
}