#include "headers/Level.hpp"
#include "headers/Game.hpp"

Level::Level()
{
    Level::loadLevel();
}

Level::~Level()
{

}

void Level::loadLevel()
{
    Level::width = 32;
    Level::height = 32;
    Level::level.resize(Level::width);
    for (int i = 0; i < Level::width; i++)
    {
        level.at(i).resize(Level::height, 0);
    }
    for(int y = 0; y < Level::getHeight(); y++)
    {
        for (int x = 0; x < Level::getWidth(); x++)
        {
            Level::level[x][y] = new Tile(1,0);
        }
    }
}

int Level::getTile(int x,int y)
{
    if(x < Level::getWidth() && x >= 0)
    {
        if(y < Level::getHeight() && y >= 0)
        {
            return Level::level[x][y]->getID();
        }
    }
    return 0;
}
sf::Rect<float> Level::getTileRect(int x,int y)
{
    int width = Game::GetTileSetSize().x;
    int height = Game::GetTileSetSize().y;
    int top = y*height;
    int left = x*width;
    return sf::Rect<float>({float(left),float(top)},{float(width),float(height)});
}
int Level::getWidth()
{
    return Level::width;
}
int Level::getHeight()
{
    return Level::height;
}
bool Level::tileIsSolid(int x,int y)
{
    if(x < Level::getWidth() && x >= 0)
    {
        if(y < Level::getHeight() && y >= 0)
        {
            return Level::level[x][y]->isSolid();
        }
    }
    return 1;
}
