#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include "../headers/TextureManager.hpp"
#include "../headers/ObjectManager.hpp"
#include "../headers/Object.hpp"
#include "../headers/Level.hpp"
#include "../headers/TileSet.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

class Game
{
public:
	static int Start();
	static sf::RenderWindow& GetWindow();
	static TextureManager& GetTextureManager();
	static Level* GetLevel();
	static sf::Vector2i GetTileSetSize();
private:
	static sf::RenderWindow Window;
	static void PollEvent();
	static void Render();
	static void Update();
	static void GameLoop();
	static bool isExiting();
	static TextureManager Textures;
	static ObjectManager Objects;
	static sf::Time dt;
	static sf::Clock deltaClock;
	static sf::View camera;
	static Level level;
	static TileSet tileset;
	static bool exit;
	static std::vector<std::vector<sf::Sprite*> > levelArea;
};


#endif // GAME
