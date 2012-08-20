#include "headers/Game.hpp"

int Game::Start()
{
    Window.create(sf::VideoMode(1366,768,32),"Acrilux",sf::Style::Close);

    exit = 0;
    sf::Image icon;
    if (!icon.loadFromFile("textures/icon.bmp"))
        return 1;
    Window.setIcon(64,64,icon.getPixelsPtr());

    Objects.newObject("Player",32,32,"Player",true,Textures.LoadTexture("textures/Player.png"));
    camera.reset(sf::FloatRect(0, 0, (float)Window.getSize().x, (float)Window.getSize().y));
    tileset.loadTileSet("textures/tileset.png",32,32);

    levelArea.resize(Window.getSize().x / tileset.getSize().x + 2);
    for (unsigned int x = 0; x <(Window.getSize().x / tileset.getSize().x + 2); x++)
    {
        levelArea.at(x).resize(Window.getSize().y / tileset.getSize().y + 2);
    }

    for(unsigned int x = 0; x <  (Window.getSize().x / tileset.getSize().x + 2); x++)
    {
        for (unsigned int y = 0; y < (Window.getSize().y / tileset.getSize().y + 2); y++)
        {
            levelArea[x][y] = new sf::Sprite;
        }
    }

    Game::GameLoop();
    return 0;

}

bool Game::isExiting()
{
    return exit;
}

void Game::GameLoop()
{
    while(!Game::isExiting())
    {
        Game::PollEvent();
        Game::Update();
        Game::Render();
        dt = deltaClock.restart();
    }
}

sf::RenderWindow& Game::GetWindow()
{
    return Window;
}
TextureManager& Game::GetTextureManager()
{
    return Textures;
}
Level* Game::GetLevel()
{
    return &level;
}

sf::Vector2i Game::GetTileSetSize()
{
    return tileset.getSize();
}

void Game::PollEvent()
{
    sf::Event event;
    while (Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            exit = 1;
    }
}

void Game::Update()
{
    Object* Player = Objects.getObjectByName("Player");
    for(unsigned int i = 0; i<Objects.objectListSize(); i++)
    {
        Objects.getObjectByID(i)->Update(dt);
    }
    Game::camera.setCenter(Player->getPosition().x,Player->getPosition().y);//may not work
}

void Game::Render()
{
    Game::Window.clear(sf::Color(0, 0, 0));
    Game::Window.setView(camera);
    {
        sf::Vector2f position;
        sf::Vector2i offset;
        sf::Vector2f _camera;
        _camera.x = camera.getCenter().x - camera.getSize().x / 2;
        _camera.y = camera.getCenter().y - camera.getSize().y / 2;
        int width = tileset.getSize().x;
        int height = tileset.getSize().y;

        offset.x = (int)_camera.x % width;
        offset.y = (int)_camera.y % height;

        for(int x = 0; x<(int)(Window.getSize().x / width + 2); x++)
        {
            for(int y = 0; y<(int)(Window.getSize().y / height + 2); y++)
            {
                levelArea[x][y]->setPosition(x * width + _camera.x - offset.x,y * height + _camera.y - offset.y);
                levelArea[x][y]->setTexture(tileset.getTile(level.getTile(((int)_camera.x - offset.x)/width+x,((int)_camera.y - offset.y)/height+y)));
                Game::Window.draw((*levelArea[x][y]));
            }
        }
    }

    for(unsigned int i = 0; i<Objects.objectListSize(); i++)
    {
        Objects.getObjectByID(i)->Draw();
    }
    Game::Window.setView(Game::Window.getDefaultView());

    Game::Window.display();
}

sf::RenderWindow Game::Window;
TextureManager Game::Textures;
ObjectManager Game::Objects;
sf::Time Game::dt;
sf::Clock Game::deltaClock;
sf::View Game::camera;
Level Game::level;
TileSet Game::tileset;
bool Game::exit;
std::vector<std::vector<sf::Sprite*> > Game::levelArea;
