#include <SFML/Graphics.hpp>
#include "headers/MenuState.hpp"
#include "headers/GameState.hpp"

int main()
{
    sf::RenderWindow Window(sf::VideoMode(640, 480), "Acrilux", sf::Style::Close);
    //Window.setFramerateLimit(60);
    sf::Image icon;
    if (!icon.loadFromFile("textures/icon.bmp"))
        return EXIT_FAILURE;
    Window.setIcon(64,64,icon.getPixelsPtr());

    int State = 1;

    AX::MenuState Menu(&Window);
    AX::GameState Game(&Window);


    while(Window.isOpen())
    {

        switch (State)
        {
            //Menu
            case 1:
            Menu.State = State;
            State = Menu.Run();
            break;
            //Game
            case 2:
            Game.State = State;
            State = Game.Run();
            break;
        }
    }

    return EXIT_SUCCESS;
}
