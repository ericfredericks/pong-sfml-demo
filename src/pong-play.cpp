#include "../include/pong-play.hpp"

void Play::ballInit()
{
    ball[CURRENT] = sf2::Object(sf::Vector2f(395,295),(sf::Vector2f)asset::tex::r_playBall,sf::Vector2f(),asset::tex::playBall,asset::tex::r_playBall);
    ballDirX = losingSide;
    ballDirY = DOWN;
    ballSpdX = 10;
    ballSpdY = 10;
}

void Play::init()
{
    lPaddle[CURRENT] = sf2::Object(sf::Vector2f(50,270),(sf::Vector2f)asset::tex::r_playPaddle,sf::Vector2f(),asset::tex::playPaddle,asset::tex::r_playPaddle);
    rPaddle[CURRENT] = sf2::Object(sf::Vector2f(740,270),(sf::Vector2f)asset::tex::r_playPaddle,sf::Vector2f(),asset::tex::playPaddle,asset::tex::r_playPaddle);
    paddleSpeed = 10;
    ballInit();

    map = sf2::Map("media/map/play.txt",40,30,sf::Vector2f(20,20));
    map.sendTexture(&asset::tex::playBlock);
    map.createVertexArrays();

    lScore = 0;
    lScoreText = asset::fnt::t_menu0;
    lScoreText.setString(std::to_string(lScore));
    lScoreText.setPosition(200,0);
    rScore = 0;
    rScoreText = asset::fnt::t_menu0;
    rScoreText.setString(std::to_string(rScore));
    rScoreText.setPosition(600,0);

    screenTop = map.tileSize.y*2;
    screenBottom = map.tileSize.y*28;

    losingSide = LEFT;
}

void Play::update()
{
    lPaddle[DELTA] = sf2::Object(sf::Vector2f(),sf::Vector2f());
    rPaddle[DELTA] = sf2::Object(sf::Vector2f(),sf::Vector2f());
    ball[DELTA] = sf2::Object(sf::Vector2f(),sf::Vector2f());


    // Pause
    if (sf2::Input::sinceKey(sf::Keyboard::Escape).asMilliseconds() > 50)
        game::state.push((State*)game::pause);
    // lPaddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (lPaddle[CURRENT].top-paddleSpeed > screenTop)
            lPaddle[DELTA].y = -paddleSpeed;
        else
        {
            while (lPaddle[CURRENT].top > screenTop)
                lPaddle[CURRENT].y--;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (lPaddle[CURRENT].bottom+paddleSpeed < screenBottom)
            lPaddle[DELTA].y = paddleSpeed;
        else
        {
            while (lPaddle[CURRENT].bottom < screenBottom)
                lPaddle[CURRENT].y++;
        }
    }
    // rPaddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (rPaddle[CURRENT].top-paddleSpeed > screenTop)
            rPaddle[DELTA].y = -paddleSpeed;
        else
        {
            while (rPaddle[CURRENT].top > screenTop)
                rPaddle[CURRENT].y--;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (rPaddle[CURRENT].bottom+paddleSpeed < screenBottom)
            rPaddle[DELTA].y = paddleSpeed;
        else
        {
            while (rPaddle[CURRENT].bottom < screenBottom)
                rPaddle[CURRENT].y++;
        }
    }
    // Ball
    switch (ballDirY)
    {
        case UP:
            if (ball[CURRENT].top-ballSpdY > screenTop)
                ball[DELTA].y = -ballSpdY;
            else
            {
                while (ball[CURRENT].top > screenTop)
                    ball[CURRENT].y--;
                ballDirY = DOWN;
            }
            break;
        case DOWN:
            if (ball[CURRENT].bottom+ballSpdY < screenBottom)
                ball[DELTA].y = ballSpdY;
            else
            {
                while (ball[CURRENT].bottom < screenBottom)
                    ball[CURRENT].y++;
                ballDirY = UP;
            }
            break;
    }

    switch (ballDirX)
    {
        case LEFT:
            if (!collisionPoint(ball[CURRENT].left-ballSpdX,ball[DELTA].y+ball[CURRENT].top,lPaddle[CURRENT]))
                ball[DELTA].x = -ballSpdX;
            // Collision w lpaddle
            else
            {
                while (ball[CURRENT].left > lPaddle[CURRENT].right)
                    ball[CURRENT].x--;
                ballDirX = RIGHT;
                losingSide = RIGHT;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    ballSpdY *= (ball[DELTA].y < 0 ? 0.5 : 1.5);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    ballSpdY *= (ball[DELTA].y > 0 ? 0.5 : 1.5);
                else
                    ballSpdY = 6;
            }
            break;
        case RIGHT:
            if (!collisionPoint(ball[CURRENT].right+ballSpdX,ball[DELTA].y+ball[CURRENT].top,rPaddle[CURRENT]))
                ball[DELTA].x = ballSpdX;
            // Collision w rpaddle
            else
            {
                while (ball[CURRENT].right < rPaddle[CURRENT].left)
                    ball[CURRENT].x++;
                ballDirX = LEFT;
                losingSide = LEFT;
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    ballSpdY *= (ball[DELTA].y < 0 ? 0.5 : 1.5);
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    ballSpdY *= (ball[DELTA].y > 0 ? 0.5 : 1.5);
                else
                    ballSpdY = 6;
            }
            break;
    }

    if ((ball[CURRENT].right < 0)||(ball[CURRENT].left > game::window.getSize().x))
    {
        ballInit();
        switch (losingSide)
        {
            case LEFT:
                rScore++;
                rScoreText.setString(std::to_string(rScore));
                break;
            case RIGHT:
                lScore++;
                lScoreText.setString(std::to_string(lScore));
        }
    }
}

void Play::display()
{
    game::window.clear();
    game::window.draw(map);
    interpolate(lPaddle);
    interpolate(rPaddle);
    interpolate(ball);
    game::window.draw(lPaddle[CURRENT]);
    game::window.draw(rPaddle[CURRENT]);
    game::window.draw(ball[CURRENT]);
    game::window.draw(lScoreText);
    game::window.draw(rScoreText);
    game::window.display();
}

void Play::interpolate(sf2::Object* _object)
{
    _object[CURRENT].x += (_object[DELTA].x * 25/60);
    _object[CURRENT].y += (_object[DELTA].y * 25/60);
}

void Play::exit()
{}

bool Play::collisionPoint(float _x,float _y,sf2::Object _object)
{
    sf::FloatRect hitbox = sf::FloatRect(_object.hitbox.getPosition(),_object.hitbox.getSize());
    if (hitbox.contains(_x,_y))
        return true;
    return false;
}
