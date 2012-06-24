#include "headers/Level.hpp"

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
			Level::level[x][y] = new Tile(x%2+1);
		}
	}
}

int Level::getTile(int x,int y)
{
	if(x < Level::getWidth() and x >= 0)
	{
		if(y < Level::getHeight() and y >= 0)
		{
			return Level::level[x][y]->getID();
		}
	}
	return 0;
}
int Level::getWidth()
{
	return Level::width;
}
int Level::getHeight()
{
	return Level::height;
}
