/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(const sf::Texture &texture, const sf::Vector2f &pos, const float &speed,
                            const sf::Color &startColor, const sf::Color &endColor, int health)
{
    _texture = texture;
    _pos = pos;
    _health = health;
    _maxHealth = health;
    _sprite.setTexture(_texture);
    _sprite.setPosition(_pos);
    _animationClock.restart();
    _deathClock.restart();
    _startColor = startColor;
    _endColor = endColor;
    _speed = speed;
    _isAlive = true;
    _deathAnimation = false;
    _deathClock.restart();
    _deathFinish = false;
}

Entity::~Entity()
{
}

bool Entity::isAlive() const
{
    return (_isAlive);
}

bool Entity::isDeathFinish() const
{
    return (_deathFinish);
}

void Entity::setIsAlive(bool isAlive)
{
    _isAlive = isAlive;
}


sf::FloatRect Entity::getGlobalBounds() const
{
    return (_sprite.getGlobalBounds());
}

sf::FloatRect Entity::getLocalBounds() const
{
    return (_sprite.getLocalBounds());
}

float Entity::getElapsedTime() const
{
    return (_animationClock.getElapsedTime().asSeconds());
}

void Entity::restartClock()
{
    _animationClock.restart();
}

sf::Vector2f Entity::getPos() const
{
    return (_pos);
}

sf::Vector2f Entity::getSize() const
{
    return (sf::Vector2f{getGlobalBounds().width, getGlobalBounds().height});
}

void Entity::setHealth(int health)
{
    _health = health;
}

void Entity::setPos(const sf::Vector2f &pos)
{
    _pos = pos;
    _sprite.setPosition(_pos);
}

void Entity::setColor(const sf::Color &color)
{
    _sprite.setColor(color);
}

void Entity::setRotation(const float &angle)
{
    _sprite.rotate(angle);
}

void Entity::drawSprite(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

void Entity::drawParticles(sf::RenderWindow &window)
{
    glPointSize(7);
    _particleSystem.drawParticles(window);
}

void Entity::update()
{
    if (!_isAlive)
        _deathFinish = true;
}