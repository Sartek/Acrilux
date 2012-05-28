#ifndef MENUSTATE
#define MENUSTATE
#include <SFML/Graphics.hpp>
namespace AX
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
        sf::Text Text1;
        void PollEvent();
    };
}

#endif // MENUSTATE
