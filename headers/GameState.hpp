#ifndef GAMESTATE
#define GAMESTATE
#include <SFML/Graphics.hpp>
#include "../headers/TextureManager.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
namespace AX
{
    class GameState
    {
    public:
        GameState(sf::RenderWindow* Window);
        ~GameState();
        int State;
        int Run();
    private:
        sf::RenderWindow* Window;
        void PollEvent();
        void Render();
        TextureManager Textures;
    };
}

#endif // GAMESTATE
