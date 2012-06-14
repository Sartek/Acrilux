#include "headers/GameState.hpp"
using namespace AX;
GameState::GameState(sf::RenderWindow* Window)
{
    this->Window = Window;
    State = 2;
    Objects.newObject("Player",32,32,true,Textures.LoadTexture("textures/grass.png"));
    Objects.newObject(64*6,64*6,true,Textures.LoadTexture("textures/grass.png"));
    Objects.newObject(64*5,64*6,true,Textures.LoadTexture("textures/grass.png"));
}

GameState::~GameState()
{

}

int GameState::Run()
{
	GameState::PollEvent();
	GameState::Update();
	GameState::Render();
	dt = deltaClock.restart();
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
	//Player
	{
		Object* Player = Objects.getObjectByName("Player");
		sf::Vector2f PlayerPosition = Player->getPosition();
		sf::Vector2f PlayerPositionL = Player->getPositionL();
		sf::Vector2f PlayerDirection((PlayerPosition.x - PlayerPositionL.x),(PlayerPosition.y - PlayerPositionL.y));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			PlayerPosition.x = PlayerPosition.x - (256 * dt.asSeconds());
			if(PlayerPosition.x < 0)
				PlayerPosition.x = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			PlayerPosition.x = PlayerPosition.x + (256 * dt.asSeconds());
			if(PlayerPosition.x > 640 - 32)
				PlayerPosition.x = 640 - 32;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			PlayerPosition.y = PlayerPosition.y - (256 * dt.asSeconds());
			if(PlayerPosition.y < 0)
				PlayerPosition.y = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			PlayerPosition.y = PlayerPosition.y + (256 * dt.asSeconds());
			if(PlayerPosition.y > 480 - 32)
				PlayerPosition.y = 480 - 32;
		}
		Player->setPosition(PlayerPosition.x,PlayerPosition.y);

	}

	//physics
	for(unsigned int i = 0;i<Objects.objectListSize();i++)
	{
		for(unsigned int ii = i+1;ii<(Objects.objectListSize());ii++)
		{
			Object* Object1 = Objects.getObjectByID(i);
			Object* Object2 = Objects.getObjectByID(ii);
			sf::Vector2f pos1 = Object1->getPosition();
			sf::Vector2f pos1L = Object1->getPositionL();//WARNING NOT USED
			float w1 = Object1->getWidth();
			float h1 = Object1->getHeight();
			sf::Vector2f pos2 = Object2->getPosition();
			sf::Vector2f pos2L = Object2->getPositionL();//WARNING NOT USED
			float w2 = Object2->getWidth();
			float h2 = Object2->getHeight();
			if(pos1.x > pos2.x and pos1.x < (pos2.x + w2)) {
				if(pos1.y > pos2.y and pos1.y < (pos2.y+h2)) {
					std::cout << "top left\n";
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
				if(pos1.y + h1 > pos2.y and pos1.y + h1 < (pos2.y+h2)) {
					std::cout << "bottom left\n";
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
			}
			if(pos1.x + w1 > pos2.x and pos1.x + w1 < (pos2.x + w2)) {
				if(pos1.y > pos2.y and pos1.y < (pos2.y+h2)) {
					std::cout << "top right\n";
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
				if(pos1.y + h1 > pos2.y and pos1.y + h1 < (pos2.y+h2)) {
					std::cout << "bottom right\n";
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
			}
		}
	}


}

void GameState::Render()
{
	GameState::Window->clear(sf::Color(0, 0, 0));
	for(unsigned int i = 0;i<Objects.objectListSize();i++)
	{
		Object* object = Objects.getObjectByID(i);
		if(object->isDrawable())
		{
			object->sprite.setTexture(Textures.GetTexture(object->textureID()));
			GameState::Window->draw(object->sprite);
		}
	}
    GameState::Window->display();
}
