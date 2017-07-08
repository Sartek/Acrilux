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
    sf::Vector2i TileSize = Game::GetTileSetSize();
    sf::Vector2i Tile;
    sf::Vector2i TileN;
    Level* level =  Game::GetLevel();
    Tile.x = ((int)Player::getPosition().x /TileSize.x);
    Tile.y = ((int)Player::getPosition().y /TileSize.y);
    Tile.x = ((int)Player::getNextRect(dt).left /TileSize.x);
    Tile.y = ((int)Player::getNextRect(dt).top /TileSize.y);
    sf::Rect<float> PlayerNext;
    sf::Rect<float> TileRect;
    PlayerNext = Player::getNextRect(dt);
    TileRect = level->getTileRect(Tile.x,Tile.y-1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(level->tileIsSolid(Tile.x,Tile.y-1) && (PlayerNext.intersects(TileRect)))
        {
            Player::setVelocity(Player::getVelocity().x,0);
        }
        else
        {
            Player::setVelocity(Player::getVelocity().x,-256);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(level->tileIsSolid(Tile.x,Tile.y)==0)
        {
            Player::setVelocity(Player::getVelocity().x,256);
        }
        else
        {
            Player::setVelocity(Player::getVelocity().x,0);
        }
    }
    else
    {
        Player::setVelocity(Player::getVelocity().x,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(level->tileIsSolid(Tile.x - 1,Tile.y)==0)
        {
            Player::setVelocity(-256,Player::getVelocity().y);
        }
        else
        {
            Player::setVelocity(0,Player::getVelocity().y);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(level->tileIsSolid(Tile.x + 1,Tile.y)==0)
        {
            Player::setVelocity(256,Player::getVelocity().y);
        }
        else
        {
            Player::setVelocity(0,Player::getVelocity().y);
        }
    }
    else
    {
        Player::setVelocity(0,Player::getVelocity().y);
    }
    Player::setPosition(Player::getPosition().x + (Player::getVelocity().x * dt.asSeconds()),Player::getPosition().y + (Player::getVelocity().y * dt.asSeconds()));
}
