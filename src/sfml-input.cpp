#include "../include/sfml-input.hpp"

// Variables
//sf::Clock sf2::Input::prevKeyClocks[5];
sf::Clock sf2::Input::prevKeyClock;
sf::Time sf2::Input::timeSince;
//int sf2::Input::prevKeys[5];
int sf2::Input::prevKey;
sf::Time sf2::Input::sinceKey(sf::Keyboard::Key _key);
const sf::Time sf2::Input::InputMinimum = sf::milliseconds(50);
/*
sf::Time sf2::Input::sinceKey(sf::Keyboard::Key _key)
{
    if (sf::Keyboard::isKeyPressed(_key))
    {
        // Repeat key
        for (int i=0;i<(int)sizeof(prevKeys);i++)
        {
            if (_key == prevKeys[i])
            {
                timeSince = prevKeyClocks[i].getElapsedTime();
                prevKeyClocks[i].restart();
                return timeSince;
            }
        }
        // New key displaces previous keys
        for (int i=(int)sizeof(prevKeys)-1;i>0;i--)
        {
            prevKeys[i] = prevKeys[i-1];
            prevKeyClocks[i] = prevKeyClocks[i-1];
        }
        prevKeys[0] = _key;
        prevKeyClocks[0].restart();
        //
        timeSince = INPUTMIN;
        return timeSince;
    }
    return sf::Time();
}
*/

sf::Time sf2::Input::sinceKey(sf::Keyboard::Key _key)
{
    if (sf::Keyboard::isKeyPressed(_key))
    {
        // repeat key
        if (_key == prevKey)
        {
            timeSince = prevKeyClock.restart();
            return timeSince;
        }
        // new key
        prevKey = _key;
        prevKeyClock.restart();
        return InputMinimum;
    }
    return sf::Time();
}
