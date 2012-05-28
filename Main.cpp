#include <SFML/Graphics.hpp>
#include "headers/MenuState.hpp"
#include "headers/GameState.hpp"

int main()
{
    sf::RenderWindow Window(sf::VideoMode(640, 480), "Lone Walker", sf::Style::Close);
    Window.SetFramerateLimit(60);
    sf::Image icon;
    if (!icon.LoadFromFile("sprites/icon.bmp"))
        return EXIT_FAILURE;
    Window.SetIcon(64,64,icon.GetPixelsPtr());

    int State = 1;

    LW::MenuState Menu(&Window);
    LW::GameState Game(&Window);


    while(Window.IsOpened())
    {
        sf::Event event;
        while (Window.PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                Window.Close();
        }

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
