#include "headers/TileSet.hpp"

TileSet::TileSet()
{
}

TileSet::~TileSet()
{
	//dtor
}

void TileSet::loadTileSet(std::string file,int w,int h)
{
	TileSet::size.x = w;
	TileSet::size.y = h;
	TileSet::tileset.loadFromFile(file);
	sf::Vector2u tilesetSize;
	tilesetSize.x = TileSet::tileset.getSize().x;
	tilesetSize.y = TileSet::tileset.getSize().y;
	sf::Image tempimage;
	tempimage.create(w,h);
	tiles.resize(tilesetSize.x/w + tilesetSize.y/h);
	for(unsigned int x = 0;x < tilesetSize.x/w;x++)
	{
		for(unsigned int y = 0;y < tilesetSize.y/h;y++)
		{
			sf::IntRect sourceRect = sf::IntRect(x*w,y*h,w,h);
			tempimage.copy(TileSet::tileset,0,0,sourceRect, false);
			tiles.at(x).loadFromImage(tempimage);
		}
	}
}

sf::Vector2i TileSet::getSize()
{
	return TileSet::size;
}

sf::Texture& TileSet::getTile(int id)
{
	return tiles.at(id);
}

