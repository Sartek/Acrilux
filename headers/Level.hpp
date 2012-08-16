#ifndef LEVEL
#define LEVEL
#include "../headers/Tile.hpp"
#include <vector>
#include <SFML/Graphics/Rect.hpp>


class Level
{
	public:
		Level();
		~Level();
		int getTile(int x,int y);
		sf::Rect<float> getTileRect(int x,int y);
		bool tileIsSolid(int x,int y);
		int getWidth();
		int getHeight();
		void loadLevel();
	private:
		std::vector<std::vector<Tile*> > level;
		int width;
		int height;
};

#endif // LEVEL
