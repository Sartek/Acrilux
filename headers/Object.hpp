#ifndef OBJECT
#define OBJECT
#include <SFML/Graphics.hpp>


class Object
{
	public:
		Object(float x,float y,bool draw,int texture_id);
		~Object();
		bool isDrawable();
		sf::Vector2f getPosition();
		sf::Vector2f getPositionL();
		sf::Vector2f getVelocity();
		virtual void update(sf::Time dt);
		void setVelocity(float x,float y);
		void setPosition(float x,float y);
		int textureID();
		float getWidth();
		float getHeight();
		void Draw();

	private:
		int textureid;
		bool drawable;
		sf::Vector2f position;
		sf::Vector2f positionL;
		sf::Vector2f velocity;
		sf::Sprite sprite;

};

#endif // OBJECT
