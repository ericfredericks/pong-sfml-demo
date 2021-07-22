#include "../include/sfml-object.hpp"

//Static variables
bool sf2::Object::hitboxShown = false;

// Constructors
sf2::Object::Object() : x(*this),y(*this) {}

sf2::Object::Object(sf::Vector2f _position,sf::Vector2f _hitbox) : x(*this),y(*this)
{
    hitbox = sf::RectangleShape(_hitbox);
    hitbox.setFillColor(sf::Color::Red);
    x = _position.x;
    y = _position.y;
}
sf2::Object::Object
(
       sf::Vector2f _position,
       sf::Vector2f _hitbox,
       sf::Vector2f _hitboxOffset,
       const sf::Texture& _texture,
       sf::Vector2i _textureRect
) : x(*this),y(*this),hitboxOffset(_hitboxOffset)
{
    sprite.setTexture(_texture);
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(),_textureRect));
    hitbox = sf::RectangleShape(_hitbox);
    hitbox.setFillColor(sf::Color::Red);
    x = _position.x;
    y = _position.y;
}

// Public methods
sf2::Object& sf2::Object::operator=(const sf2::Object& _right)
{
    hitbox = _right.hitbox;
    hitboxOffset = _right.hitboxOffset;
    sprite = _right.sprite;
    hitboxShown = _right.hitboxShown;
    right = _right.right;
    bottom = _right.bottom;
    left = _right.left;
    top = _right.top;
    x = _right.x;
    y = _right.y;
    return *this;
}
void sf2::Object::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(sprite);
    if (hitboxShown)
        target.draw(hitbox);
}

//      SUBCLASS X
//      SUBCLASS X
//      SUBCLASS X
float sf2::Object::X::operator+(const float& _right)
{
    result = value + _right;
    return result;
}
float sf2::Object::X::operator-(const float& _right)
{
    result = value - _right;
    return result;
}
float sf2::Object::X::operator*(const float& _right)
{
    result = value * _right;
    return result;
}
float sf2::Object::X::operator/(const float& _right)
{
    result = value / _right;
    return result;
}
float& sf2::Object::X::operator=(const float& _right)
{
    value = _right;
    reposition();
    return value;
}
void sf2::Object::X::operator=(const X& _right)
{
    value = _right.value;
}
bool sf2::Object::X::operator<(const float& _right)
{
    if (value < _right)
        return true;
    return false;
}
bool sf2::Object::X::operator>(const float& _right)
{
    if (value > _right)
        return true;
    return false;
}
float& sf2::Object::X::operator+=(const float& _right)
{
    value += _right;
    reposition();
    return value;
}
float& sf2::Object::X::operator-=(const float& _right)
{
    value -= _right;
    reposition();
    return value;
}
float& sf2::Object::X::operator*=(const float& _right)
{
    value *= _right;
    reposition();
    return value;
}
float& sf2::Object::X::operator/=(const float& _right)
{
    value /= _right;
    reposition();
    return value;
}
bool sf2::Object::X::operator==(const float& _right)
{
    if (value == _right)
        return true;
    return false;
}
bool sf2::Object::X::operator!=(const float& _right)
{
    if (value != _right)
        return true;
    return false;
}
bool sf2::Object::X::operator<=(const float& _right)
{
    if (value <= _right)
        return true;
    return false;
}
bool sf2::Object::X::operator>=(const float& _right)
{
    if (value >= _right)
        return true;
    return false;
}
float& sf2::Object::X::operator++(int _right)
{
    value++;
    reposition();
    return value;
}
float& sf2::Object::X::operator--(int _right)
{
    value--;
    reposition();
    return value;
}
void sf2::Object::X::reposition()
{
    parent.sprite.setPosition(value,parent.sprite.getPosition().y);
    parent.hitbox.setPosition(value+parent.hitboxOffset.x,parent.hitbox.getPosition().y);
    parent.right = parent.hitbox.getPosition().x+parent.hitbox.getSize().x;
    parent.left = parent.hitbox.getPosition().x;
}
//      SUBCLASS Y
//      SUBCLASS Y
//      SUBCLASS Y
float sf2::Object::Y::operator+(const float& _right)
{
    result = value + _right;
    return result;
}
float sf2::Object::Y::operator-(const float& _right)
{
    result = value - _right;
    return result;
}
float sf2::Object::Y::operator*(const float& _right)
{
    result = value * _right;
    return result;
}
float sf2::Object::Y::operator/(const float& _right)
{
    result = value / _right;
    return result;
}
float& sf2::Object::Y::operator=(const float& _right)
{
    value = _right;
    reposition();
    return value;
}
void sf2::Object::Y::operator=(const Y& _right)
{
    value = _right.value;
}
bool sf2::Object::Y::operator<(const float& _right)
{
    if (value < _right)
        return true;
    return false;
}
bool sf2::Object::Y::operator>(const float& _right)
{
    if (value > _right)
        return true;
    return false;
}
float& sf2::Object::Y::operator+=(const float& _right)
{
    value += _right;
    reposition();
    return value;
}
float& sf2::Object::Y::operator-=(const float& _right)
{
    value -= _right;
    reposition();
    return value;
}
float& sf2::Object::Y::operator*=(const float& _right)
{
    value *= _right;
    reposition();
    return value;
}
float& sf2::Object::Y::operator/=(const float& _right)
{
    value /= _right;
    reposition();
    return value;
}
bool sf2::Object::Y::operator==(const float& _right)
{
    if (value == _right)
        return true;
    return false;
}
bool sf2::Object::Y::operator!=(const float& _right)
{
    if (value != _right)
        return true;
    return false;
}
bool sf2::Object::Y::operator<=(const float& _right)
{
    if (value <= _right)
        return true;
    return false;
}
bool sf2::Object::Y::operator>=(const float& _right)
{
    if (value >= _right)
        return true;
    return false;
}
float& sf2::Object::Y::operator++(int _right)
{
    value++;
    reposition();
    return value;
}
float& sf2::Object::Y::operator--(int _right)
{
    value--;
    reposition();
    return value;
}
void sf2::Object::Y::reposition()
{
    parent.sprite.setPosition(parent.sprite.getPosition().x,value);
    parent.hitbox.setPosition(parent.hitbox.getPosition().x,value+parent.hitboxOffset.y);
    parent.top = parent.hitbox.getPosition().y;
    parent.bottom = parent.hitbox.getPosition().y+parent.hitbox.getSize().y;
}
