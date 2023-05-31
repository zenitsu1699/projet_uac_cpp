/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Layer
*/


#include "Layer.hpp"

Layer::Layer(const sf::Texture &texture, const sf::Vector2f &pos, const bool &active, const float &speed) : Entity(texture, pos, speed)
{
    _isActive = active;
}

Layer::~Layer()
{
}

void Layer::setActive(const bool &activation)
{
    _isActive = activation;
}

bool Layer::isActive() const
{
    return (_isActive);
}