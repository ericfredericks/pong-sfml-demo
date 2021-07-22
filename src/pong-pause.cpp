#include "../include/pong-pause.hpp"

void Pause::init()
{
    text0 = asset::fnt::t_menu0;
    text1 = text0;
    text0.setString("PAUSED");
    text0.setPosition(5,0);
    text1.setString("R TO RESET");
    text1.setPosition(5,600-35);
}

void Pause::update()
{
    if (sf2::Input::sinceKey(sf::Keyboard::Escape).asMilliseconds() > 50)
        game::state.pop();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        game::play->init();
        game::state.pop();
    }
}

void Pause::display()
{
    game::window.draw(text0);
    game::window.draw(text1);
    game::window.display();
}

void Pause::exit()
{}
