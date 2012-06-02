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
    GameState::Update();
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

void GameState::Update()
{

}

void GameState::Render()
{
	GameState::Window->clear(sf::Color(0, 0, 0));
	for(unsigned int i = 0;i<Objects.objectListSize();i++)
	{
		Object object = Objects.getObject(i);
		if(object.isDrawable())
		{
			object.sprite.setTexture(Textures.GetTexture(object.textureID()));
			GameState::Window->draw(object.sprite);
		}
	}
    GameState::Window->display();
}
