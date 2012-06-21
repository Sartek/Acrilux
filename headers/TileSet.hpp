#ifndef TILESET
#define TILESET
#include <SFML/Graphics.hpp>

class TileSet
{
	public:
		TileSet();
		~TileSet();
		void loadTileSet(std::string file,int w,int h);
	private:
	sf::Texture* tileset;
	int width;
	int height;
};

#endif // TILESET
