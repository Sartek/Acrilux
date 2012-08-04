#include "headers/Player.hpp"
#include "headers/Game.hpp"

Player::Player() :
_isLoaded(false)
{
}

Player::~Player()
{
}

void Player::Update(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		Player::setVelocity(Player::getVelocity().x,-256);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		Player::setVelocity(Player::getVelocity().x,256);
	}
	else
	{
		Player::setVelocity(Player::getVelocity().x,0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		Player::setVelocity(-256,Player::getVelocity().y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Player::setVelocity(256,Player::getVelocity().y);
	}
	else
	{
		Player::setVelocity(0,Player::getVelocity().y);
	}
	Player::setPosition(Player::getPosition().x + (Player::getVelocity().x * dt.asSeconds()),Player::getPosition().y + (Player::getVelocity().y * dt.asSeconds()));
}
