#ifndef PONG_PLAY_H
#define PONG_PLAY_H

#include <SFML/Graphics.hpp>
#include "state.hpp"
#include "pong-asset.hpp"
#include "pong-game.hpp"
#include "sfml-object.hpp"
#include "sfml-input.hpp"

class Play : public State
{
public:
    void init() override;
    void update() override;
    void display() override;
    void exit() override;
private:
    sf2::Object lPaddle[2];
    sf2::Object rPaddle[2];
    sf2::Object ball[2];
    bool ballDirX;
    bool ballDirY;
    float ballSpdY;
    float ballSpdX;

    sf2::Map map;
    int lScore;
    int rScore;
    sf::Text lScoreText;
    sf::Text rScoreText;


    float paddleSpeed;
    float screenBottom;
    float screenTop;
    bool losingSide;

    enum {UP,DOWN};
    enum {LEFT,RIGHT};
    enum {CURRENT,DELTA};

    void interpolate(sf2::Object* _object);
    void ballInit();
    bool collisionPoint(float _x,float _y,sf2::Object _object);
};

#endif
