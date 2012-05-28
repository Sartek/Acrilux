#ifndef MENUSTATE
#define MENUSTATE
#include <SFML/Graphics.hpp>
namespace LW
{
    class MenuState
    {
    public:
        MenuState(sf::RenderWindow* Window);
        ~MenuState();
        int State;
        int Run();
    private:
        sf::RenderWindow* Window;
        sf::Font Arial;
        sf::Text Text1;
        void PollEvent();
    };
}

#endif // MENUSTATE
