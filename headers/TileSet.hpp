#ifndef TILESET
#define TILESET
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class TileSet
{
	public:
		TileSet();
		~TileSet();
		void loadTileSet(std::string file,int w,int h);
		sf::Texture& getTile(int id);
		int getWidth();
		int getHeight();
	private:
		sf::Image tileset;
		int width;
		int height;
		std::vector<sf::Texture> tiles;
};

#endif // TILESET
