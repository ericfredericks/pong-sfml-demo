#ifndef PONG_PAUSE_H
#define PONG_PAUSE_H

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "pong-asset.hpp"
#include "pong-game.hpp"
#include "sfml-input.hpp"
#include "pong-play.hpp"

class Pause : public State
{
public:
    void init() override;
    void update() override;
    void display() override;
    void exit() override;
private:
    sf::Text text0;
    sf::Text text1;
};

#endif
