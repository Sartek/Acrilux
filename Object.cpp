#include "headers/Object.hpp"
#include "headers/Game.hpp"

Object::Object() :
_isLoaded(false)
{
}

Object::~Object()
{
}

void Object::Load(float x,float y,bool draw,int texture_id)
{
	if(!_isLoaded)
	{
		_isLoaded = true;
		Object::setPosition(x,y);
		BoundingBox.width = Object::sprite.getGlobalBounds().width;
		BoundingBox.height = Object::sprite.getGlobalBounds().height;

		Object::drawable = draw;
		Object::sprite.setPosition(Object::BoundingBox.left,Object::BoundingBox.top);
		textureid = texture_id;
		Object::sprite.setTexture(Game::GetTextureManager().GetTexture(textureid));
	}
}

bool Object::isDrawable()
{
	return drawable;
}

void Object::setPosition(float x,float y)
{
	Object::BoundingBox.left = x;
	Object::BoundingBox.top = y;
	Object::sprite.setPosition(Object::BoundingBox.left,Object::BoundingBox.top);
}

sf::Vector2f Object::getPosition()
{
	return sf::Vector2f(Object::BoundingBox.left,Object::BoundingBox.top);
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

void Object::Update(sf::Time dt)
{
	Object::setPosition(Object::getPosition().x + (Object::getVelocity().x * dt.asSeconds()),Object::getPosition().y + (Object::getVelocity().y * dt.asSeconds()));
}

float Object::getWidth()
{
	return BoundingBox.width;
}

float Object::getHeight()
{
	return BoundingBox.height;
}

sf::Rect<float> Object::getRect()
{
	return BoundingBox;
}
sf::Rect<float> Object::getNextRect(sf::Time dt)
{
	return sf::Rect<float>(Object::getPosition().x + (Object::getVelocity().x * dt.asSeconds()),Object::getPosition().y + (Object::getVelocity().y * dt.asSeconds()),BoundingBox.width,BoundingBox.height);
}

sf::Vector2f Object::getCenter()
{
	return sf::Vector2f(BoundingBox.left+(BoundingBox.width/2),BoundingBox.top+(BoundingBox.height/2));
}

int Object::textureID()
{
	return textureid;
}
void Object::Draw()
{
	Game::GetWindow().draw(Object::sprite);
}
