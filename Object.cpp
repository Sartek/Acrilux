#include "headers\Object.hpp"

Object::Object(int x,int y,bool draw,int texture_id)
{
	Object::position.x = x;
	Object::position.y = y;
	Object::drawable = draw;
	Object::sprite.setPosition(Object::position.x,Object::position.y);
	textureid = texture_id;
}

Object::~Object()
{
}

bool Object::isDrawable()
{
	return drawable;
}

void Object::setPosition(int x,int y)
{
	Object::position.x = x;
	Object::position.y = y;
}

sf::Vector2i Object::Position()
{
	return Object::position;
}

int Object::textureID()
{
	return textureid;
}
