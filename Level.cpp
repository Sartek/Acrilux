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
    for (int i = 0; i < Level::height; i++)
    {
        level.at(i).resize(Level::height, 0);
    }
	for(int i = 0; i < Level::getWidth(); i++)
	{
		for (int ii = 0; ii < Level::getHeight(); ii++)
		{
			Level::level[i][ii] = new Tile(ii%2+1);
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
