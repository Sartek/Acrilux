#include "headers/GameState.hpp"
using namespace AX;
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
    GameState::PollEvent();
    GameState::Render();
    return State;
}
void GameState::PollEvent()
{
	sf::Event event;
	while (Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			Window->close();
		if((event.type ==sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			GameState::State = 1;
	}
}
void GameState::Render()
{
	GameState::Window->clear(sf::Color(0, 0, 0));
    GameState::Window->display();
}
