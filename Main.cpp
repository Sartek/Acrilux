#include "headers/Game.hpp"
#include "config.h"
#include <iostream>

int main()
{
	std::cout << "Version " << Acrilux_VERSION_MAJOR << "." << Acrilux_VERSION_MINOR << std::endl;
    return Game::Start();
}
