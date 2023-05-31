/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Parallax
*/


#include "Parallax.hpp"

Parallax::Parallax()
{
}

Parallax::~Parallax()
{
    for (auto iter : _layersVec) {
        delete iter.second.first.first;
        delete iter.second.first.second;
        delete iter.second.second.first;
        delete iter.second.second.second;
    }
}

void Parallax::create(const int &speed)
{
    _speed = speed;
    for (int i = 0; i < 4; i++)
        _direction[i] = false;
    _direction[DOWN] = true;
    _direction[LEFT] = true;
    _layerTextures[BACKGROUND] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/BKG 2/Bkg 2 Nebula.png");
    _layerTextures[PLANET] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/BKG 2/Bkg 2 Planet.png");
    _layerTextures[FARTHEST] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/OLD/small_stars1.png");
    _layerTextures[FARE] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/OLD/small_stars2.png");
    _layerTextures[CLOSE] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/BKG 2/Bkg 2 Middle Stars NO.png");
    _layerTextures[CLOSEST] = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/parallax/BKG 2/Bkg 2 Meteors.png");

    add(1.0, BACKGROUND, true);
    add(1.2, PLANET, true);
    add(1.4, FARTHEST, true);
    add(1.6, FARE, true);
    add(1.9, CLOSE, true);
    add(2.2, CLOSEST, true);
}

void Parallax::add(const float &speed, const Layers &type, const bool &active)
{
    _layersVec.push_back(
        make_pair(
            speed,
            make_pair(
                make_pair(
                    new Layer(_layerTextures[type], sf::Vector2f{0, 0}, active, speed),
                    new Layer(_layerTextures[type], sf::Vector2f{-float(_layerTextures[type].getSize().x), 0}, active, speed)
                ),
                make_pair(
                    new Layer(_layerTextures[type], sf::Vector2f{0, -float(_layerTextures[type].getSize().y)}, active, speed),
                    new Layer(_layerTextures[type], sf::Vector2f{-float(_layerTextures[type].getSize().x), -float(_layerTextures[type].getSize().y)}, active, speed)
                )
            )
        )
    );
}

void Parallax::event(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Down)
            _direction[DOWN] = true;
        if (event.key.code == sf::Keyboard::Left)
            _direction[LEFT] = true;
        if (event.key.code == sf::Keyboard::Right)
            _direction[RIGHT] = true;
        if (event.key.code == sf::Keyboard::Up)
           _direction[UP] = true;
    } else if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Down)
            _direction[DOWN] = false;
        if (event.key.code == sf::Keyboard::Left)
            _direction[LEFT] = false;
        if (event.key.code == sf::Keyboard::Right)
            _direction[RIGHT] = false;
        if (event.key.code == sf::Keyboard::Up)
           _direction[UP] = false;
    }
}

void Parallax::setDirection(const std::vector<bool> &direction)
{
    if (direction.size() == 0)
        return;

    int i = 0;
    for (auto it : direction) {
        _direction[i] = it;
        i++;
    }
}

void Parallax::setPosition(struct std::pair<float, std::pair<std::pair<Layer *, Layer *>, std::pair<Layer *, Layer *>>> iter)
{
    float elapsedTime = iter.second.first.first->getElapsedTime();
    if (_direction[RIGHT]) {
        iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x + iter.first * elapsedTime * _speed, iter.second.first.first->getPos().y));
        iter.second.first.second->setPos(sf::Vector2f(iter.second.first.second->getPos().x + iter.first * elapsedTime * _speed, iter.second.first.second->getPos().y));
        iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x + iter.first * elapsedTime * _speed, iter.second.second.first->getPos().y));
        iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x + iter.first * elapsedTime * _speed, iter.second.second.second->getPos().y));
    }
    if (_direction[LEFT]) {
        iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x - iter.first * elapsedTime * _speed, iter.second.first.first->getPos().y));
        iter.second.first.second->setPos(sf::Vector2f(iter.second.first.second->getPos().x - iter.first * elapsedTime * _speed, iter.second.first.second->getPos().y));
        iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x - iter.first * elapsedTime * _speed, iter.second.second.first->getPos().y));
        iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x - iter.first * elapsedTime * _speed, iter.second.second.second->getPos().y));
    }
    if (_direction[UP]) {
        iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x, iter.second.first.first->getPos().y - iter.first * elapsedTime * _speed));
        iter.second.first.second->setPos(sf::Vector2f(iter.second.first.second->getPos().x, iter.second.first.second->getPos().y - iter.first * elapsedTime * _speed));
        iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x, iter.second.second.first->getPos().y - iter.first * elapsedTime * _speed));
        iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.second.second->getPos().y - iter.first * elapsedTime * _speed));
    }
    if (_direction[DOWN]) {
        iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x, iter.second.first.first->getPos().y + iter.first * elapsedTime * _speed));
        iter.second.first.second->setPos(sf::Vector2f(iter.second.first.second->getPos().x, iter.second.first.second->getPos().y + iter.first * elapsedTime * _speed));
        iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x, iter.second.second.first->getPos().y + iter.first * elapsedTime * _speed));
        iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.second.second->getPos().y + iter.first * elapsedTime * _speed));
    }
}

void Parallax::fillEmptySpace(struct std::pair<float, std::pair<std::pair<Layer *, Layer *>, std::pair<Layer *, Layer *>>> iter)
{
    if (_direction[RIGHT]) {
        if (iter.second.first.first->getPos().x >= iter.second.first.first->getSize().x)
            iter.second.first.first->setPos(sf::Vector2f(iter.second.first.second->getPos().x - iter.second.first.second->getSize().x, iter.second.first.first->getPos().y));
        if (iter.second.first.second->getPos().x >= iter.second.first.second->getSize().x)
            iter.second.first.second->setPos(sf::Vector2f(iter.second.first.first->getPos().x - iter.second.first.second->getSize().x, iter.second.first.second->getPos().y));
        if (iter.second.second.first->getPos().x >= iter.second.second.first->getSize().x)
            iter.second.second.first->setPos(sf::Vector2f(iter.second.second.second->getPos().x - iter.second.second.second->getSize().x, iter.second.second.first->getPos().y));
        if (iter.second.second.second->getPos().x >= iter.second.second.second->getSize().x)
            iter.second.second.second->setPos(sf::Vector2f(iter.second.second.first->getPos().x - iter.second.second.second->getSize().x, iter.second.second.second->getPos().y));
    }
    if (_direction[LEFT]) {
        if (iter.second.first.first->getPos().x <= -iter.second.first.first->getSize().x)
            iter.second.first.first->setPos(sf::Vector2f(iter.second.first.second->getPos().x + iter.second.first.second->getSize().x, iter.second.first.first->getPos().y));
        if (iter.second.first.second->getPos().x <= -iter.second.first.second->getSize().x)
            iter.second.first.second->setPos(sf::Vector2f(iter.second.first.first->getPos().x + iter.second.first.second->getSize().x, iter.second.first.second->getPos().y));
        if (iter.second.second.first->getPos().x <= -iter.second.second.first->getSize().x)
            iter.second.second.first->setPos(sf::Vector2f(iter.second.second.second->getPos().x + iter.second.second.second->getSize().x, iter.second.second.first->getPos().y));
        if (iter.second.second.second->getPos().x <= -iter.second.second.second->getSize().x)
            iter.second.second.second->setPos(sf::Vector2f(iter.second.second.first->getPos().x + iter.second.second.second->getSize().x, iter.second.second.second->getPos().y));
    }
    if (_direction[UP]) {
        if (iter.second.first.first->getPos().y <= -iter.second.first.first->getSize().y)
            iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x, iter.second.second.first->getPos().y + iter.second.first.first->getSize().y));
        if (iter.second.first.second->getPos().y <= -iter.second.first.second->getSize().y)
            iter.second.first.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.second.first->getPos().y + iter.second.second.second->getSize().y));
        if (iter.second.second.first->getPos().y <= -iter.second.second.first->getSize().y)
            iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x, iter.second.first.first->getPos().y + iter.second.second.first->getSize().y));
        if (iter.second.second.second->getPos().y <= -iter.second.second.second->getSize().y)
            iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.first.second->getPos().y + iter.second.second.second->getSize().y));
    }
    if (_direction[DOWN]) {
        if (iter.second.first.first->getPos().y >= iter.second.first.first->getSize().y)
            iter.second.first.first->setPos(sf::Vector2f(iter.second.first.first->getPos().x, iter.second.second.first->getPos().y - iter.second.first.first->getSize().y));
        if (iter.second.first.second->getPos().y >= iter.second.first.second->getSize().y)
            iter.second.first.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.second.first->getPos().y - iter.second.second.second->getSize().y));
        if (iter.second.second.first->getPos().y >= iter.second.second.first->getSize().y)
            iter.second.second.first->setPos(sf::Vector2f(iter.second.second.first->getPos().x, iter.second.first.first->getPos().y - iter.second.second.first->getSize().y));
        if (iter.second.second.second->getPos().y >= iter.second.second.second->getSize().y)
            iter.second.second.second->setPos(sf::Vector2f(iter.second.second.second->getPos().x, iter.second.first.second->getPos().y - iter.second.second.second->getSize().y));
    }
}

void Parallax::update()
{
    for (auto iter : _layersVec) {
        if (iter.second.first.first->isActive() == true) {
            setPosition(iter);
            fillEmptySpace(iter);
            iter.second.first.first->restartClock();
        }
    }
}


void Parallax::draw(sf::RenderWindow &window) const
{
    for (auto iter : _layersVec) {
        if (iter.second.first.first->isActive() == true) {
            iter.second.first.first->drawSprite(window);
            iter.second.first.second->drawSprite(window);
            iter.second.second.first->drawSprite(window);
            iter.second.second.second->drawSprite(window);
        }
    }
}