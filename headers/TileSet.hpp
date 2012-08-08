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
		sf::Vector2i getSize();
	private:
		sf::Image tileset;
		sf::Vector2i size;
		std::vector<sf::Texture> tiles;
};

#endif // TILESET
