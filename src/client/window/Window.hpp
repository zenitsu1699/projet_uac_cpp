/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <asio.hpp>


#include "../parallax/Parallax.hpp"
// #include "Game.hpp"
// #include "Menu.hpp"
#include "../../tools/ProjectException.hpp"

class Window {
    public:
        enum Scene {
            MENU,
            NEWLETTER,
            SUBCRIBER,
        };

        Window(const std::string &title);
        ~Window();

        /**
         * @brief Start the gameLoop
         * 
         * @return ** void 
         */
        void gameLoop();

    protected:
    private:
        void event();
        void update();
        void draw();
        // void readTcp();
        // void readUdp();

        sf::RenderWindow _window;
        sf::Event _event;
        Parallax _parallax;
        // Menu _menu;
        // Game _game;
        Scene _scene;
        bool _lostConnection;
        bool _gameStarted;
        bool _closeGame;

        // asio::io_context _io_context;
        // asio::ip::tcp::resolver *_resolver;
        // asio::ip::tcp::socket *_tcpSocket;
        // asio::ip::udp::socket *_udpSocket;
        // char _tcpBuf[1024];
        // char _udpBuf[1024];
        // asio::error_code _tcpError;
        // asio::error_code _udpError;
        // asio::ip::tcp::endpoint _tcpEndpoint;
        // asio::ip::udp::endpoint _udpEndpoint;
};

#endif /* !WINDOW_HPP_ */
