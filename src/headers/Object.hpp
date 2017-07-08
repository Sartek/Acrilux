#ifndef OBJECT
#define OBJECT
#include <SFML/Graphics.hpp>


class Object
{
public:
    Object();
    virtual ~Object();
    virtual bool isDrawable();
    virtual void Load(float x,float y,bool draw,int texture_id);
    virtual sf::Vector2f getPosition();
    virtual sf::Vector2f getVelocity();
    virtual void Update(sf::Time dt);
    virtual void setVelocity(float x,float y);
    virtual void setPosition(float x,float y);
    virtual int textureID();
    virtual float getWidth();
    virtual float getHeight();
    virtual sf::Rect<float> getRect();
    virtual sf::Rect<float> getNextRect(sf::Time dt);
    virtual sf::Vector2f getCenter();
    virtual void Draw();
protected:
    int textureid;
    bool drawable;
    bool _isLoaded;
    sf::Rect<float> BoundingBox;
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Sprite sprite;


};

#endif // OBJECT
