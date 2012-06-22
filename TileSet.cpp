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
	TileSet::width = w;
	TileSet::height = h;
	TileSet::tileset.loadFromFile(file);
	sf::Vector2u tilesetSize;
	tilesetSize.x = TileSet::tileset.getSize().x;
	tilesetSize.y = TileSet::tileset.getSize().y;
	sf::Image tempimage;
	tempimage.create(w,h);
	tiles.resize(tilesetSize.x/w + tilesetSize.y/h);
	for(int i = 0;i < tilesetSize.x/w;i++)
	{
		for(int ii = 0;ii < tilesetSize.y/h;ii++)
		{
			sf::IntRect sourceRect = sf::IntRect(i*w,ii*h,w,h);
			tempimage.copy(TileSet::tileset,0,0,sourceRect, false);
			tiles.at(i).loadFromImage(tempimage);
		}
	}
}

int TileSet::getWidth()
{
	return TileSet::width;
}

int TileSet::getHeight()
{
	return TileSet::height;
}

sf::Texture& TileSet::getTile(int id)
{
	return tiles.at(id);
}

