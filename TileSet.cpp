#include "headers/TileSet.hpp"

TileSet::TileSet()
{
	TileSet::tileset = new sf::Texture;
}

TileSet::~TileSet()
{
	//dtor
}

void TileSet::loadTileSet(std::string file,int w,int h)
{
	TileSet::width = w;
	TileSet::height = h;
	TileSet::tileset->loadFromFile(file);
}
