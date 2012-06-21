#include "headers/Tile.hpp"

Tile::Tile(int id)
{
	Tile::id = id;
}

Tile::~Tile()
{
	//dtor
}

int Tile::getID()
{
	return id;
}

void Tile::setID(int id)
{
	Tile::id = id;
}
