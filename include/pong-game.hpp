#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "state.hpp"
class Play;
class Pause;
#include <SFML/Graphics.hpp>

namespace game
{
    extern StateStack state;
    extern sf::RenderWindow window;
    extern Play* play;
    extern Pause* pause;

}

#endif
