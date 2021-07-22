#ifndef SFML2_INPUT_H
#define SFML2_INPUT_H

#include <SFML/Window.hpp>

namespace sf2
{
    namespace Input
    {
        //extern sf::Clock prevKeyClocks[5];
        extern sf::Clock prevKeyClock;
        extern sf::Time timeSince;
        //extern int prevKeys[5];
        extern int prevKey;
        extern sf::Time sinceKey(sf::Keyboard::Key);
        extern const sf::Time InputMinimum;
    };
}

#endif
