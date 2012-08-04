#include "headers/Object.hpp"
#include "headers/Game.hpp"

Object::Object(float x,float y,bool draw,int texture_id)
{
	Object::setPosition(x,y);
	Object::drawable = draw;
	Object::sprite.setPosition(Object::position.x,Object::position.y);
	textureid = texture_id;
	Object::sprite.setTexture(Game::GetTextureManager().GetTexture(textureid));
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

void Object::setVelocity(float x,float y)
{
	Object::velocity.x = x;
	Object::velocity.y = y;
}

void Object::update(sf::Time dt)
{
	Object::setPosition(Object::getPosition().x + (Object::getVelocity().x * dt.asSeconds()),Object::getPosition().y + (Object::getVelocity().y * dt.asSeconds()));
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
void Object::Draw()
{
	Game::GetWindow().draw(Object::sprite);
}
