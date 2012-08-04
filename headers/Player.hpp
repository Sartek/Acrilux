#ifndef PLAYER
#define PLAYER
#include "Object.hpp"
#include "SFML\Graphics.hpp"
class Player :
	public Object
{
public:
	Player();
	~Player();
	void Update(sf::Time dt);
private:
	bool _isLoaded;
};
#endif // PLAYER
