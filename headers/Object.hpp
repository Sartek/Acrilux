#ifndef OBJECT
#define OBJECT
#include <SFML/Graphics.hpp>


class Object
{
	public:
		Object(int x,int y,bool draw,int texture_id);
		~Object();
		bool isDrawable();
		sf::Vector2i Position();
		void setPosition(int x,int y);
		sf::Sprite sprite;
		int textureID();

	private:
		int textureid;
		bool drawable;
		sf::Vector2i position;
};

#endif // OBJECT
