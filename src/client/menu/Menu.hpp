/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <asio.hpp>

#include "../common/WarningBox.hpp"
#include "Connection.hpp"
// #include "RoomsList.hpp"
// #include "Room.hpp"

class Menu {
    public:
        Menu();
        ~Menu();

        /**
         * @brief Create Menu
         * 
         * @param window 
         * @param tcpBuf 
         * @param udpBuf 
         * @return ** void 
         */
        void create(const sf::RenderWindow &window, char *tcpBuf, char *udpBuf);

        /**
         * @brief Draw Menu
         * 
         * @param window 
         * @return ** void 
         */
        void draw(sf::RenderWindow &window) const;

        /**
         * @brief Menu events
         * 
         * @param event 
         * @param window 
         * @param tcpEndpoint 
         * @param tcpSocket 
         * @param udpSocket 
         * @return ** void 
         */
        void event(const sf::Event &event, const sf::RenderWindow &window, asio::ip::tcp::endpoint &tcpEndpoint, asio::ip::tcp::socket &tcpSocket, asio::ip::udp::socket &udpSocket);
        void event(const sf::Event &event, const sf::RenderWindow &window);

        /**
         * @brief Update menu
         * 
         * @param window 
         * @param udpEndpoint 
         * @param udpSocket 
         * @param scene 
         * @return ** void 
         */
        void update(const sf::RenderWindow &window, asio::ip::udp::endpoint &udpEndpoint, asio::ip::udp::socket &udpSocket, const bool &scene);
        void update(const sf::RenderWindow &window, const bool &scene);

        /**
         * @brief Set the Alert object
         * 
         * @return ** void 
         */
        void setAlert();

        // /**
        //  * @brief Set the In Room object
        //  * 
        //  * @param inUserProfil 
        //  * @param tcpSocket 
        //  * @return ** void 
        //  */
        // void setinUserProfil(const bool &inUserProfil, asio::ip::tcp::socket &tcpSocket);

        /**
         * @brief Stop the music
         * 
         * @return ** void 
         */
        void stopMusic();

        /**
         * @brief Start the music
         * 
         * @return ** void 
         */
        void startMusic();

    protected:
    private:
        void connect(const sf::Event &event, const sf::RenderWindow &window);
        void getDefaultInput();
        // void joinUserProfil(std::vector<std::string> &cmdTcp, asio::ip::udp::endpoint &udpEndpoint, asio::ip::udp::socket &udpSocket);
        void openAlert();
        // void leaveUserProfil(asio::ip::udp::socket &udpSocket);
        bool startAnimation(const sf::RenderWindow &window);

        sf::RectangleShape _background;
        WarningBox _alert;
        Connection _connection;
        // RoomsList _roomsList;
        bool _connected;
        bool _inUserProfil;
        sf::Texture _logoTexture;
        sf::Sprite _logo;
        // char *_tcpBuf;
        // char *_udpBuf;
        // Room _room;
        std::string _ip;
        sf::Clock _animation;
        bool _animationEnd;
        sf::Music _music;
};

#endif /* !MENU_HPP_ */
