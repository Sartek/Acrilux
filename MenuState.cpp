#include "headers/MenuState.hpp"
using namespace AX;
MenuState::MenuState(sf::RenderWindow* Window)
{
    this->Window = Window;
    Text1.setString("Press Any Key");
    Text1.setPosition( 640/4*1.5, 440 );
    State = 1;

}
MenuState::~MenuState()
{

}
int MenuState::Run()
{
    MenuState::Window->clear();
    MenuState::Window->draw(Text1);
    MenuState::Window->display();
    MenuState::PollEvent();

    return MenuState::State;
}
void MenuState::PollEvent()
{
        sf::Event event;
        while (Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window->close();
            if(event.type ==sf::Event::KeyPressed)
                MenuState::State = 2;
        }
}
