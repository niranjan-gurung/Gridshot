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
}