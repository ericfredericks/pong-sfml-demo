#ifndef SFML2_OBJECT_H
#define SFML2_OBJECT_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

namespace sf2
{
    class Object : public sf::Drawable
    {
        class X
        {
        public:
            float operator+(const float&);
            float operator-(const float&);
            float operator*(const float&);
            float operator/(const float&);
            float& operator=(const float&);
            void operator=(const X&);
            bool operator<(const float&);
            bool operator>(const float&);
            float& operator+=(const float&);
            float& operator-=(const float&);
            float& operator*=(const float&);
            float& operator/=(const float&);
            bool operator==(const float&);
            bool operator!=(const float&);
            bool operator<=(const float&);
            bool operator>=(const float&);
            float& operator++(int);
            float& operator--(int);
            void reposition();
            X(Object& o) : parent(o) {}
        private:
            float result;
            float value;
            Object& parent;
        };
        class Y
        {
        public:
            float operator+(const float&);
            float operator-(const float&);
            float operator*(const float&);
            float operator/(const float&);
            float& operator=(const float&);
            void operator=(const Y&);
            bool operator<(const float&);
            bool operator>(const float&);
            float& operator+=(const float&);
            float& operator-=(const float&);
            float& operator*=(const float&);
            float& operator/=(const float&);
            bool operator==(const float&);
            bool operator!=(const float&);
            bool operator<=(const float&);
            bool operator>=(const float&);
            float& operator++(int);
            float& operator--(int);
            void reposition();
            Y(Object& o) : parent(o) {}
        private:
            float result;
            float value;
            Object& parent;
        };
    public:
        // Public variables
        X x;
        Y y;
        static bool hitboxShown;
        sf::RectangleShape hitbox;
        float top;
        float right;
        float bottom;
        float left;

        // Constructors
        Object();
        Object(sf::Vector2f _position,sf::Vector2f _hitbox);
        Object(sf::Vector2f _position,sf::Vector2f _hitbox,sf::Vector2f _hitboxOffset,const sf::Texture& _texture,sf::Vector2i _textureRect);

        // Public methods
        Object& operator=(const Object&);
        virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
    private:
        sf::Vector2f hitboxOffset;
        sf::Sprite sprite;
    };
}

#endif
