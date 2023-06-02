/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** UserProfil
*/

#include "UserProfil.hpp"

UserProfil::UserProfil()
{
}

UserProfil::~UserProfil()
{
}

void UserProfil::create(const sf::RectangleShape &background)
{
    getDefaultInput();

    _nameBox.create(sf::Vector2f(background.getSize().x / 3, background.getSize().y / 16), sf::Vector2f(background.getPosition().x, background.getPosition().y - background.getSize().y / 5), "Choose your name", _name, false, true);
    _loginBox.create(sf::Vector2f(background.getSize().x / 3, background.getSize().y / 16), sf::Vector2f(background.getPosition().x, background.getPosition().y), "CHoose your login", _login, true, true);
    _passwordBox.create(sf::Vector2f(background.getSize().x / 3, background.getSize().y / 16), sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 5), "Choose your password", _password, false, true);
    _disconnect.create(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 2), "Connect");
}

void UserProfil::connect(const sf::Event &event, const sf::RenderWindow &window, WarningBox &alert)
{
    if (_disconnect.event(event, window)) {
        _name = _nameBox.getInputString();
        _login = _loginBox.getInputString();
        _password = _passwordBox.getInputString();
        if (_name == "")
            alert.open("Please enter a non empty name.", true);
        else if (_login == "")
            alert.open("Please enter a non empty login.", true);
        else if (_password == "")
            alert.open("Please enter a non empty password.", true);
        // else {
        //     std::ofstream myfile;
        //     myfile.open ("src/client/menu/save.txt");
        //     myfile <<  _ip << ";" << _port << ";" << _name;
        //     myfile.close();
        //     endpoint = asio::ip::tcp::endpoint(asio::ip::address::from_string(_ip), (unsigned short)std::atoi(_port.c_str()));
        //     try {
        //         if (socket.is_open())
        //             socket.close();
        //         socket.connect(endpoint);
        //         socket.send(asio::buffer("210 " + _name + "\n"));
        //     } catch(std::exception& error) {
        //         socket.close();
        //         alert.open("UserProfil refused.", true);
        //     }
        // }
    }
}

void UserProfil::getDefaultInput()
{
    // std::string line;
    // std::ifstream saveFile ("src/client/menu/save.txt");
    // if (saveFile.is_open()) {
    //     std::getline(saveFile, line);
    //     _ip = line.substr(0, line.find(";"));
    //     if (_ip == "")
    //         _ip = "192.168.0.0";
    //     line.erase(0, _ip.size() + 1);
    //     _port = line.substr(0, line.find(";"));
    //     if (_port == "")
    //         _port = "8888";
    //     line.erase(0, _port.size() + 1);
    //     _name = line;
    //     if (_name == "")
    //         _name = "Player";
    //     saveFile.close();
    // }
    // else {
    //     _ip = "192.168.0.0";
    //     _name = "Player";
    //     _port = "8888";
    //     std::ofstream newFile ("src/client/menu/save.txt");
    //     newFile << _ip << ";" << _port << ";" << _name;
    //     newFile.close();
    // }
}

void UserProfil::event(const sf::Event &event, const sf::RenderWindow &window)
{
    _nameBox.event(event, window);
    _loginBox.event(event, window);
    _passwordBox.event(event, window);
}

void UserProfil::update(const sf::RenderWindow &window, const sf::RectangleShape &background, const bool &animationEnd, const bool &isDrawn)
{
    _nameBox.update(window, isDrawn);
    _disconnect.update(window, isDrawn);
    _loginBox.update(window, isDrawn);
    _passwordBox.update(window, isDrawn);
    if (!animationEnd) {
        _nameBox.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y - background.getSize().y / 5));
        _disconnect.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 2));
        _loginBox.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y));
        _passwordBox.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 5));
    }
}

void UserProfil::draw(sf::RenderWindow &window) const
{
    _nameBox.draw(window);
    _loginBox.draw(window);
    _passwordBox.draw(window);
    _disconnect.draw(window);
}