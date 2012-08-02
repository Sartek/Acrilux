#include "headers/GameState.hpp"
using namespace AX;
GameState::GameState(sf::RenderWindow* Window)
{
    this->Window = Window;
    State = 2;
    Objects.newObject("Player",32,32,true,Textures.LoadTexture("textures/Player_AA.png"));
    Objects.newObject(96,96,true,Textures.LoadTexture("textures/Player_AA.png"));
	camera.reset(sf::FloatRect(0, 0, this->Window->getSize().x, this->Window->getSize().y));
	tileset.loadTileSet("textures/tileset.png",32,32);

	levelArea.resize(Window->getSize().x / tileset.getWidth() + (Window->getSize().x % tileset.getWidth() ? 0 : 1));
    for (unsigned int x = 0; x <(Window->getSize().x / tileset.getWidth() + (Window->getSize().x % tileset.getWidth() ? 0 : 1)); x++)
    {
        levelArea.at(x).resize(Window->getSize().y / tileset.getHeight()+ (Window->getSize().y % tileset.getHeight() ? 2 : 3));
    }

	for(unsigned int x = 0; x <  (Window->getSize().x / tileset.getWidth() + (Window->getSize().x % tileset.getWidth() ? 0 : 1)); x++)
	{
		for (unsigned int y = 0; y < (Window->getSize().y / tileset.getHeight()+ (Window->getSize().y % tileset.getHeight() ? 2 : 3)); y++)
		{
			levelArea[x][y] = new sf::Sprite;
		}
	}
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Player->setVelocity(Player->getVelocity().x,-256);
			//PlayerPosition.x = PlayerPosition.x - (256 * dt.asSeconds());
			//if(PlayerPosition.x < 0)
			//	PlayerPosition.x = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Player->setVelocity(Player->getVelocity().x,256);
			//PlayerPosition.x = PlayerPosition.x + (256 * dt.asSeconds());
			//if(PlayerPosition.x > 640 - 32)
			//	PlayerPosition.x = 640 - 32;
		}
		else
		{
			Player->setVelocity(Player->getVelocity().x,0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Player->setVelocity(-256,Player->getVelocity().y);
			//PlayerPosition.y = PlayerPosition.y - (256 * dt.asSeconds());
			//if(PlayerPosition.y < 0)
			//	PlayerPosition.y = 0;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Player->setVelocity(256,Player->getVelocity().y);
			//PlayerPosition.y = PlayerPosition.y + (256 * dt.asSeconds());
			//if(PlayerPosition.y > 480 - 32)
			//	PlayerPosition.y = 480 - 32;
		}
		else
		{
			Player->setVelocity(0,Player->getVelocity().y);
		}
		//Player->setPosition(PlayerPosition.x,PlayerPosition.y);
		GameState::camera.setCenter(Player->getPosition().x,Player->getPosition().y);//may not work
	}

	//physics and collisons
	for(unsigned int i = 0;i<Objects.objectListSize();i++)
	{
		Object* Object1 = Objects.getObjectByID(i);
		sf::Vector2f pos1 = Object1->getPosition();
		sf::Vector2f pos1L = Object1->getPositionL();
		sf::Vector2f direction1;
		direction1.x = Object1->getPosition().x - Object1->getPositionL().x;
		direction1.y = Object1->getPosition().y - Object1->getPositionL().y;
		float w1 = Object1->getWidth();
		float h1 = Object1->getHeight();
		for(unsigned int ii = i+1;ii<(Objects.objectListSize());ii++)
		{
			Object* Object2 = Objects.getObjectByID(ii);
			sf::Vector2f pos2 = Object2->getPosition();
			sf::Vector2f pos2L = Object2->getPositionL();
			sf::Vector2f direction2;
			direction2.x = Object2->getPosition().x - Object2->getPositionL().x;
			direction2.y = Object2->getPosition().y - Object2->getPositionL().y;
			float w2 = Object2->getWidth();
			float h2 = Object2->getHeight();
			if(pos1.x > pos2.x && pos1.x < (pos2.x + w2)) {
				if(pos1.y > pos2.y && pos1.y < (pos2.y+h2)) {
					//top left
					Object1->setVelocity(Object1->getVelocity().x * -1,Object1->getVelocity().y * -1);
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
				if(pos1.y + h1 > pos2.y && pos1.y + h1 < (pos2.y+h2)) {
					//bottom left
					Object1->setVelocity(Object1->getVelocity().x * -1,Object1->getVelocity().y * -1);
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
			}
			if(pos1.x + w1 > pos2.x && pos1.x + w1 < (pos2.x + w2)) {
				if(pos1.y > pos2.y && pos1.y < (pos2.y+h2)) {
					//top right
					Object1->setVelocity(Object1->getVelocity().x * -1,Object1->getVelocity().y * -1);
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
				if(pos1.y + h1 > pos2.y && pos1.y + h1 < (pos2.y+h2)) {
					//bottom right
					Object1->setVelocity(Object1->getVelocity().x * -1,Object1->getVelocity().y * -1);
					Object1->setPosition(Object1->getPositionL().x,Object1->getPositionL().y);
				}
			}
		}
		Object1->update(dt);
	}


}

void GameState::Render()
{
	GameState::Window->clear(sf::Color(0, 0, 0));//GameState::Window->clear(sf::Color(0, 96, 254));
	GameState::Window->setView(camera);
	{
		sf::Vector2f position;
		position.x = Objects.getObjectByName("Player")->getPosition().x - (Window->getSize().x / 2);
		position.y = Objects.getObjectByName("Player")->getPosition().y - (Window->getSize().y / 2);
		sf::Vector2i offset;
		sf::Vector2i _camera;
		_camera.x = camera.getCenter().x - camera.getSize().x / 2;
		_camera.y = camera.getCenter().y - camera.getSize().y / 2;
		int width = tileset.getWidth();
		int height = tileset.getHeight();

		offset.x = _camera.x % width;
		offset.y = _camera.y % height;

		for(int x = 0;x<(Window->getSize().x / tileset.getWidth()+ (Window->getSize().x % tileset.getWidth() ? 0 : 1));x++)
		{
			for(int y = 0;y<(Window->getSize().y / tileset.getHeight()+ (Window->getSize().y % tileset.getHeight() ? 2 : 3));y++)
			{
				levelArea[x][y]->setPosition(x * width + _camera.x - offset.x,y * height + _camera.y - offset.y);
				levelArea[x][y]->setTexture(tileset.getTile(level.getTile((_camera.x - offset.x)/width+x,(_camera.y - offset.y)/height+y)));
				GameState::Window->draw((*levelArea[x][y]));
			}
		}
	}
	/*
	for(int i = 0;i< level.getHeight();i++)
	{
		for(int ii = 0;ii< (level.getWidth());ii++)
		{
			levelArea[i][ii]->setPosition(i*tileset.getHeight(),ii*tileset.getWidth());
			levelArea[i][ii]->setTexture(tileset.getTile(level.getTile(i,ii)));
			GameState::Window->draw((*levelArea[i][ii]));
		}
	}
	*/

	for(unsigned int i = 0;i<Objects.objectListSize();i++)
	{
		Object* object = Objects.getObjectByID(i);
		if(object->isDrawable())
		{
			object->sprite.setTexture(Textures.GetTexture(object->textureID()));
			GameState::Window->draw(object->sprite);
		}
	}
	GameState::Window->setView(GameState::Window->getDefaultView());

	std::ostringstream directionString;
	directionString << "X:" << Objects.getObjectByName("Player")->getPosition().x - Objects.getObjectByName("Player")->getPositionL().x << " Y:" << Objects.getObjectByName("Player")->getPosition().y - Objects.getObjectByName("Player")->getPositionL().y << "\n";
	sf::Text direction(directionString.str());
	direction.setPosition(32,32);
	//GameState::Window->draw(direction);

    GameState::Window->display();
}
