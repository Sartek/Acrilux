#ifndef GAMESTATE
#define GAMESTATE
#include <SFML/Graphics.hpp>
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
    };
}

#endif // GAMESTATE
