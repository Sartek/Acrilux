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
		virtual sf::Vector2f getPositionL();
		virtual sf::Vector2f getVelocity();
		virtual void Update(sf::Time dt);
		virtual void setVelocity(float x,float y);
		virtual void setPosition(float x,float y);
		virtual int textureID();
		virtual float getWidth();
		virtual float getHeight();
		virtual void Draw();
	protected:
		int textureid;
		bool drawable;
		bool _isLoaded;
		sf::Vector2f position;
		sf::Vector2f positionL;
		sf::Vector2f velocity;
		sf::Sprite sprite;


};

#endif // OBJECT
