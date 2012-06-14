#include "headers\Object.hpp"

Object::Object(int x,int y,bool draw,int texture_id)
{
	Object::setPosition(x,y);
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

void Object::setPosition(float x,float y)
{
	Object::positionL.x = Object::position.x;
	Object::positionL.y = Object::position.y;
	Object::position.x = x;
	Object::position.y = y;
	Object::sprite.setPosition(Object::position.x,Object::position.y);
}

sf::Vector2f Object::getPosition()
{
	return Object::position;
}

sf::Vector2f Object::getPositionL()
{
	return Object::positionL;
}

sf::Vector2f Object::getVelocity()
{
	return Object::velocity;
}

float Object::getWidth()
{
	return Object::sprite.getGlobalBounds().width;
}

float Object::getHeight()
{
	return Object::sprite.getGlobalBounds().height;
}

int Object::textureID()
{
	return textureid;
}
