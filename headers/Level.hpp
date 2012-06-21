#ifndef LEVEL
#define LEVEL
#include "../headers/Tile.hpp"
#include <vector>


class Level
{
	public:
		Level();
		~Level();
		int getTile(int x,int y);
		int getWidth();
		int getHeight();
		void loadLevel();
	private:
		std::vector<std::vector<Tile*> > level;
		int width;
		int height;
};

#endif // LEVEL
