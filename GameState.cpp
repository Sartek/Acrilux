#include "headers/GameState.hpp"
using namespace LW;
GameState::GameState(sf::RenderWindow* Window)
{
    this->Window = Window;
    State = 2;

}
GameState::~GameState()
{

}
int GameState::Run()
{
    GameState::Window->Clear(sf::Color(001, 191, 254));

    GameState::Window->Display();
    GameState::PollEvent();
    return State;
}
void GameState::PollEvent()
{
        sf::Event event;
        while (Window->PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                Window->Close();
            if((event.Type ==sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape))
                GameState::State = 1;
        }
}
