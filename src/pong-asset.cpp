#include "../include/pong-asset.hpp"

// Static variables
sf::Texture asset::tex::none;
sf::Texture asset::tex::playBlock;
sf::Vector2i asset::tex::r_playBlock = sf::Vector2i(20,20);
sf::Texture asset::tex::playPaddle;
sf::Vector2i asset::tex::r_playPaddle = sf::Vector2i(10,60);
sf::Texture asset::tex::playBall;
sf::Vector2i asset::tex::r_playBall = sf::Vector2i(10,10);

sf::Font asset::fnt::arial;
sf::Text asset::fnt::t_menu0 = sf::Text("",asset::fnt::arial);
