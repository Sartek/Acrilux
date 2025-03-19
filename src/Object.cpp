#include "headers/Object.hpp"
#include "headers/Game.hpp"

Object::Object() :
    _isLoaded(false)
    //drawable(false)
    //textureid(0)
    , sprite(Game::GetTextureManager().GetTexture(0))
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
        BoundingBox.size = Object::sprite.getGlobalBounds().size;

        Object::drawable = draw;
        Object::sprite.setPosition(Object::BoundingBox.position);
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
    Object::BoundingBox.position = {x,y};
    Object::sprite.setPosition(Object::BoundingBox.position);
}

sf::Vector2f Object::getPosition()
{
    return sf::Vector2f(Object::BoundingBox.position);
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
    return BoundingBox.size.x;
}

float Object::getHeight()
{
    return BoundingBox.size.y;
}

sf::Rect<float> Object::getRect()
{
    return BoundingBox;
}
sf::Rect<float> Object::getNextRect(sf::Time dt)
{
    return sf::Rect<float>({Object::getPosition().x + (Object::getVelocity().x * dt.asSeconds()),Object::getPosition().y + (Object::getVelocity().y * dt.asSeconds())},BoundingBox.size);
}

sf::Vector2f Object::getCenter()
{
    return sf::Vector2f({BoundingBox.position.x + (BoundingBox.size.x / 2), BoundingBox.position.y + (BoundingBox.size.y / 2)});
}

int Object::textureID()
{
    return textureid;
}
void Object::Draw()
{
    Game::GetWindow().draw(Object::sprite);
}
