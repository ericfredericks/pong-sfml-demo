#ifndef PONG_ASSET_H
#define PONG_ASSET_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "sfml-map.hpp"

namespace asset
{
    namespace tex
    {
        extern sf::Texture none;
        extern sf::Texture playBlock;
        extern sf::Vector2i r_playBlock;
        extern sf::Texture playBlock;
        extern sf::Vector2i r_playBlock;
        extern sf::Texture playPaddle;
        extern sf::Vector2i r_playPaddle;
        extern sf::Texture playBall;
        extern sf::Vector2i r_playBall;
    }

    namespace fnt
    {
        extern sf::Font arial;
        extern sf::Text t_menu0;
    }
};

#endif
