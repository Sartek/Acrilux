#include "headers/MenuState.hpp"
using namespace LW;
MenuState::MenuState(sf::RenderWindow* Window)
{
    this->Window = Window;
    if (!Arial.LoadFromFile("fonts/arial.ttf"))
        Window->Close();
    Text1.SetString("Press Any Key");
    Text1.SetFont(Arial);
    Text1.SetX(640/4*1.5);
    Text1.SetY(440);
    State = 1;

}
MenuState::~MenuState()
{

}
int MenuState::Run()
{
    MenuState::Window->Clear();
    MenuState::Window->Draw(Text1);
    MenuState::Window->Display();
    MenuState::PollEvent();

    return MenuState::State;
}
void MenuState::PollEvent()
{
        sf::Event event;
        while (Window->PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                Window->Close();
            if(event.Type ==sf::Event::KeyPressed)
                MenuState::State = 2;
        }
}
