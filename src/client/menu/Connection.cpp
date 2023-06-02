/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Connection
*/

#include "Connection.hpp"

Connection::Connection()
{
}

Connection::~Connection()
{
}

void Connection::create(const sf::RectangleShape &background)
{
    getDefaultInput();

    _loginBox.create(sf::Vector2f(background.getSize().x / 3, background.getSize().y / 16), sf::Vector2f(background.getPosition().x, background.getPosition().y - background.getSize().y / 4), "Your login", _login, false, true);
 
    _passwordBox.create(sf::Vector2f(background.getSize().x / 3, background.getSize().y / 16), sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 6), "Your password", _password, false, true);
 
    _connect.create(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 2), "Connect");
}

// void Connection::connect(const sf::Event &event, const sf::RenderWindow &window, asio::ip::tcp::endpoint &endpoint, asio::ip::tcp::socket &socket, WarningBox &alert)
// {
//     if (_connect.event(event, window)) {
//         _login = _loginBox.getInputString();

//         _password = _passwordBox.getInputString();

//         if (_login == "")
//             alert.open("Please enter a non empty login.", true);

//         else if (_password == "")
//             alert.open("Please enter a non empty password.", true);
//         // else {
//         //     std::ofstream myfile;
//         //     myfile.open ("src/client/menu/save.txt");
//         //     myfile <<  _ip << ";" << _port << ";" << _name;
//         //     myfile.close();
//         //     endpoint = asio::ip::tcp::endpoint(asio::ip::address::from_string(_ip), (unsigned short)std::atoi(_port.c_str()));
//         //     try {
//         //         if (socket.is_open())
//         //             socket.close();
//         //         socket.connect(endpoint);
//         //         socket.send(asio::buffer("210 " + _name + "\n"));
//         //     } catch(std::exception& error) {
//         //         socket.close();
//         //         alert.open("Connection refused.", true);
//         //     }
//         // }
//     }
// }

void Connection::connect(const sf::Event &event, const sf::RenderWindow &window, WarningBox &alert)
{
    if (_connect.event(event, window)) {
        _login = _loginBox.getInputString();

        _password = _passwordBox.getInputString();

        if (_login == "")
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
        //         alert.open("Connection refused.", true);
        //     }
        // }
    }
}

void Connection::getDefaultInput()
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

void Connection::event(const sf::Event &event, const sf::RenderWindow &window)
{
    _loginBox.event(event, window);

    _passwordBox.event(event, window);
}

void Connection::update(const sf::RenderWindow &window, const sf::RectangleShape &background, const bool &animationEnd, const bool &isDrawn)
{
    _loginBox.update(window, isDrawn);
    _connect.update(window, isDrawn);
    _passwordBox.update(window, isDrawn);
    if (!animationEnd) {
        _loginBox.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y - background.getSize().y / 5));
        _connect.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 2));
        _passwordBox.setPosition(sf::Vector2f(background.getPosition().x, background.getPosition().y + background.getSize().y / 5));
    }
}

void Connection::draw(sf::RenderWindow &window) const
{
    _loginBox.draw(window);
    _passwordBox.draw(window);
    _connect.draw(window);
}