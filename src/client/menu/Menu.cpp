/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::create(const sf::RenderWindow &window, char *tcpBuf, char *udpBuf)
{
    _background.setSize(sf::Vector2f(window.getSize().x / 1.5, window.getSize().y / 1.5));
    _background.setFillColor(sf::Color(0, 0, 0, 150));
    _background.setOutlineColor(sf::Color::White);
    _background.setOutlineThickness(2.0);
    _background.setOrigin(sf::Vector2f(_background.getSize().x / 2, _background.getSize().y / 2));

    _background.setPosition(sf::Vector2f(window.getSize().x / 2, -_background.getSize().y / 2));

    _animationEnd = false;

    _connection.create(_background);
    _connected = false;
    _animation.restart();

    _music.openFromFile("assets/sounds/menu_music.ogg");
    _music.setLoop(true);

    // _tcpBuf = tcpBuf;
    // _udpBuf = udpBuf;
    _inUserProfil = false;

    _alert.create(sf::Vector2f(_background.getPosition().x, _background.getPosition().y));

    _logoTexture = AssetHandle<sf::Texture>::getAssetHandle().getAsset("assets/menu/game_news.png");
    _logo.setTexture(_logoTexture);
    _logo.setOrigin(sf::Vector2f(_logo.getTextureRect().width / 3, _logo.getTextureRect().height / 3));
    _logo.setPosition(sf::Vector2f(_background.getPosition().x - _background.getPosition().x / 10, _background.getPosition().y - _background.getSize().y / 1.6));
    _logo.setScale(sf::Vector2f(_logo.getScale().x - _logo.getScale().x / 2, _logo.getScale().y - _logo.getScale().y / 2));

}

// void Menu::event(const sf::Event &event, const sf::RenderWindow &window, asio::ip::tcp::endpoint &tcpEndpoint, asio::ip::tcp::socket &tcpSocket, asio::ip::udp::socket &udpSocket)
// {
//     if (!_alert.isOpen() && _animationEnd) {
//         if (!_connected) {
//             _connection.event(event, window);
//             _connection.connect(event, window, tcpEndpoint, tcpSocket, _alert);
//             // _ip = tcpEndpoint.address().to_string();
//         } else if (!_inUserProfil) {
//             // _UserProfilsList.event(event, window, tcpSocket);
//             // _connected = _UserProfilsList.disconnect(event, window, tcpSocket);
//         } else {
//             // _UserProfil.event(event, window, tcpSocket, udpSocket);
//         }
//     } else
//         _alert.event(event, window);
// }

void Menu::event(const sf::Event &event, const sf::RenderWindow &window)
{
    if (!_alert.isOpen() && _animationEnd) {
        if (!_connected) {
            _connection.event(event, window);
            _connection.connect(event, window, _alert);
            // _ip = tcpEndpoint.address().to_string();
        } else if (!_inUserProfil) {
            // _UserProfilsList.event(event, window, tcpSocket);
            // _connected = _UserProfilsList.disconnect(event, window, tcpSocket);
        } else {
            // _UserProfil.event(event, window, tcpSocket, udpSocket);
        }
    } else
        _alert.event(event, window);
}

void Menu::openAlert()
{
    // std::string stringBuf(_tcpBuf);
    // if (stringBuf.size() > 0 && stringBuf.find("500") != std::string::npos) {
    //     stringBuf.erase(0, 4);
    //     if (stringBuf.find('\n') != std::string::npos)
    //         stringBuf.pop_back();
    //     _alert.open(stringBuf, true);
    // }
}

// void Menu::joinUserProfil(std::vector<std::string> &cmdTcp, asio::ip::udp::endpoint &udpEndpoint, asio::ip::udp::socket &udpSocket)
// {
//     if (_connected && cmdTcp.size() > 1 && cmdTcp[0] == "230") {
//         if (cmdTcp.back().find('\n') != std::string::npos)
//             cmdTcp.back().pop_back();
//         _inUserProfil = true;
//         // _UserProfil.setUserProfil(cmdTcp, udpEndpoint, udpSocket, _ip);
//     }
// }

// void Menu::leaveUserProfil(asio::ip::udp::socket &udpSocket)
// {
//     // std::string strBuf(_tcpBuf);
//     // if (strBuf.find('\n') != std::string::npos)
//     //     strBuf.pop_back();
//     // if (_connected && _inUserProfil && strBuf.size() > 0 && strBuf == "100") {
//     //     _inUserProfil = false;
//     //     udpSocket.close();
//     // }
// }

bool Menu::startAnimation(const sf::RenderWindow &window)
{
    if (_animationEnd)
        return (_animationEnd);
    if (_background.getPosition().y < window.getSize().y / 2) {
        _background.setPosition(sf::Vector2f(_background.getPosition().x, _background.getPosition().y + 2000 * _animation.getElapsedTime().asSeconds()));
        _logo.setPosition(sf::Vector2f(_background.getPosition().x - _background.getSize().y / 7, _background.getPosition().y - _background.getSize().y / 1.5));
    } else {
        // _UserProfilsList.create(_background);
        // _UserProfil.create(_background);
        _alert.create(sf::Vector2f(_background.getPosition().x, _background.getPosition().y));
        return (true);
    }
    _animation.restart();
    return (false);
}

// void Menu::setinUserProfil(const bool &inUserProfil, asio::ip::tcp::socket &tcpSocket)
// {
//     _inUserProfil = inUserProfil;
//     if (_inUserProfil == false) {
//         _alert.close();
//         // tcpSocket.send(asio::buffer("235 " + _UserProfil.getUserProfilId() + "\n"));
//         // _UserProfil.create(_background);
//     }
// }

// void Menu::update(const sf::RenderWindow &window, asio::ip::udp::endpoint &udpEndpoint, asio::ip::udp::socket &udpSocket, const bool &scene)
// {
//     _animationEnd = startAnimation(window);
//     // std::vector<std::string> cmdTcp = SEPParsor::parseCommands(_tcpBuf);
//     // std::vector<std::string> cmdUdp = SEPParsor::parseCommands(_udpBuf);
//     openAlert();
//     // joinUserProfil(cmdTcp, udpEndpoint, udpSocket);
//     // leaveUserProfil(udpSocket);
//     _connection.update(window, _background, _animationEnd, !_connected && !_alert.isOpen());
//     // _UserProfilsList.update(cmdTcp, window, _connected, _connected && !_inUserProfil && !_alert.isOpen());
//     // _UserProfil.update(cmdUdp, window, _inUserProfil && scene != true && !_alert.isOpen());
//     _alert.update(window);
// }

void Menu::update(const sf::RenderWindow &window,const bool &scene)
{
    _animationEnd = startAnimation(window);
    // std::vector<std::string> cmdTcp = SEPParsor::parseCommands(_tcpBuf);
    // std::vector<std::string> cmdUdp = SEPParsor::parseCommands(_udpBuf);
    openAlert();
    // joinUserProfil(cmdTcp, udpEndpoint, udpSocket);
    // leaveUserProfil(udpSocket);
    _connection.update(window, _background, _animationEnd, !_connected && !_alert.isOpen());
    // _UserProfilsList.update(cmdTcp, window, _connected, _connected && !_inUserProfil && !_alert.isOpen());
    // _UserProfil.update(cmdUdp, window, _inUserProfil && scene != true && !_alert.isOpen());
    _alert.update(window);
}

void Menu::setAlert()
{
    _alert.open("Lost connection with the server.", false);
}

void Menu::stopMusic()
{
    if (_music.getStatus() != _music.Stopped)
        _music.stop();
}

void Menu::startMusic()
{
    if (_music.getStatus() != _music.Playing)
        _music.play();
}

void Menu::draw(sf::RenderWindow &window) const
{
    if (!_alert.isOpen()) {
        window.draw(_background);
        window.draw(_logo);
        if (!_connected)
            _connection.draw(window);
        // else if (!_inUserProfil)
            // _UserProfilsList.draw(window);
        // else
            // _UserProfil.draw(window);
    }
    _alert.draw(window);
}