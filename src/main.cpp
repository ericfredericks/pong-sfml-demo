#include <SFML/Graphics.hpp>

#include <iostream>
#include "../include/pong-game.hpp"
#include "../include/pong-asset.hpp"
#include "../include/pong-play.hpp"
#include "../include/pong-pause.hpp"

bool loadTextures();
bool loadFonts();
void loadPointers();

sf::Clock gameClock;
const sf::Int32 updateIntervalMs = 1000 / 25;
const sf::Int32 displayIntervalMs = 1000 / 60;
sf::Int32 lastUpdateMs = gameClock.getElapsedTime().asMilliseconds();
sf::Int32 lastDisplayMs = gameClock.getElapsedTime().asMilliseconds();
sf::Int32 untilUpdateMs;
sf::Int32 untilDisplayMs;
bool workDone;

int main()
{
    if (!loadTextures())
        return -1;
    if (!loadFonts())
        return -1;
    loadPointers();

    game::window.create(sf::VideoMode(800,600),"",sf::Style::Close);
    game::state.push(game::play);

    while (game::window.isOpen())
    {
        sf::Event event;
        while (game::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game::window.close();
        }
        if (game::state.states.empty())
            game::window.close();

        // Compare interval ___ with difference in time since last ___
        untilUpdateMs = updateIntervalMs + (lastUpdateMs - gameClock.getElapsedTime().asMilliseconds());
        untilDisplayMs = displayIntervalMs + (lastDisplayMs - gameClock.getElapsedTime().asMilliseconds());
        if (untilUpdateMs <= 0)
        {
            game::state.update();
            lastUpdateMs = gameClock.getElapsedTime().asMilliseconds();
            workDone = true;
        }
        if (untilDisplayMs <= 0)
        {
            game::state.display();
            lastDisplayMs = gameClock.getElapsedTime().asMilliseconds();
            workDone = true;
        }
        if (!workDone)
        {
            if (untilDisplayMs < untilUpdateMs)
                sf::sleep(sf::milliseconds(untilDisplayMs));
            else
                sf::sleep(sf::milliseconds(untilUpdateMs));
        }
    }
    return 0;
}

bool loadTextures()
{
    if (!asset::tex::none.loadFromFile("media/img/none.png"))
        return false;
    if (!asset::tex::playBlock.loadFromFile("media/img/play/block.png"))
        return false;
    if (!asset::tex::playPaddle.loadFromFile("media/img/play/paddle.png"))
        return false;
    if (!asset::tex::playBall.loadFromFile("media/img/play/ball.png"))
        return false;
    return true;
}
bool loadFonts()
{
    if (!asset::fnt::arial.loadFromFile("media/fnt/arial.ttf"))
        return false;
    asset::fnt::t_menu0.setOutlineColor(sf::Color::Black);
    asset::fnt::t_menu0.setOutlineThickness(5.f);
    return true;
}
Play play;
Pause pause;
void loadPointers()
{
    game::play = &play;
    game::pause = &pause;
}
