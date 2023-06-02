/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** UserCard
*/

#include "UserCard.hpp"

UserCard::UserCard()
{
}

UserCard::~UserCard()
{
}

void UserCard::create(const sf::Vector2f &pos, const sf::Vector2f &size, const std::string &name, const std::string &ready, const sf::Vector2f &factors)
{
    _background.setSize(sf::Vector2f(size.x, size.y));
    _background.setFillColor(sf::Color::Black);
    _background.setOutlineColor(sf::Color::White);
    _background.setOutlineThickness(2.0);
    _background.setPosition(sf::Vector2f(pos.x, pos.y));

    _font = AssetHandle<sf::Font>::getAssetHandle().getAsset("assets/fonts/OxygenMono-Regular.ttf");

    _name.setString(name + '\n');
    _name.setScale(factors);
    _name.setFont(_font);
    _name.setOrigin(sf::Vector2f(_name.getOrigin().x, _name.getGlobalBounds().height / 3));
    _name.setPosition(sf::Vector2f(_background.getPosition().x + _background.getSize().x / 10, _background.getPosition().y + _background.getSize().y / 1.9));

    _readyTexture = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/menu/ready.png");
    _notReadyTexture = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/menu/notready.png");

    if (ready == "0") _ready.setTexture(_notReadyTexture);
    else _ready.setTexture(_readyTexture);
    _ready.setOrigin(sf::Vector2f(_ready.getTextureRect().width / 2, _ready.getTextureRect().height / 2));
    _ready.setPosition(sf::Vector2f(_background.getPosition().x + _background.getSize().x / 1.15, _background.getPosition().y + _background.getSize().y / 2));

}

std::string UserCard::getName() const
{
    return (_name.getString());
}

void UserCard::setReady(const std::string &state)
{
    if (state == "1")
        _ready.setTexture(_readyTexture);
    else
        _ready.setTexture(_notReadyTexture);
}

void UserCard::draw(sf::RenderWindow &window) const
{
    window.draw(_background);
    window.draw(_name);
    window.draw(_ready);
}

sf::Vector2f UserCard::getPosition() const
{
    return (_background.getPosition());
}

void UserCard::setPosition(const sf::Vector2f &pos)
{
    _background.setPosition(pos);
    _name.setPosition(sf::Vector2f(_background.getPosition().x + _background.getSize().x / 10, _background.getPosition().y + _background.getSize().y / 1.9));
    _ready.setPosition(sf::Vector2f(_background.getPosition().x + _background.getSize().x / 1.15, _background.getPosition().y + _background.getSize().y / 2));
}

sf::Vector2f UserCard::getSize() const
{
    return (_background.getSize());
}