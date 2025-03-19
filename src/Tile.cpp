#include "headers/Tile.hpp"

Tile::Tile(int id,bool _solid)
{
    Tile::id = id;
    Tile::solid = _solid;
}

Tile::~Tile()
{
}

int Tile::getID()
{
    return id;
}

void Tile::setID(int id)
{
    Tile::id = id;
}

bool Tile::isSolid()
{
    return Tile::solid;
}

void Tile::Solid(bool x)
{
    Tile::solid = x;
}
