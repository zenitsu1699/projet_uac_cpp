/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Connection
*/


#ifndef CONNECTION_HPP_
#define CONNECTION_HPP_

#include <SFML/Graphics.hpp>
#include <asio.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include "../common/InputBox.hpp"
#include "../common/Button.hpp"
// #include "ValidateIp.hpp"
#include "../common/WarningBox.hpp"

class Connection {
    public:
        Connection();
        ~Connection();

    /**
     * @brief Create Connection
     * 
     * @param background 
     * @return ** void 
     */
    void create(const sf::RectangleShape &background);

    /**
     * @brief Connection events
     * 
     * @param event 
     * @param window 
     * @return ** void 
     */
    void event(const sf::Event &event, const sf::RenderWindow &window);

    /**
     * @brief Update Connection
     * 
     * @param window 
     * @param background 
     * @param animationEnd 
     * @param isDrawn 
     * @return ** void 
     */
    void update(const sf::RenderWindow &window, const sf::RectangleShape &background, const bool &animationEnd, const bool &isDrawn);

    /**
     * @brief Draw Connection
     * 
     * @param window 
     * @return ** void 
     */
    void draw(sf::RenderWindow &window) const;

    /**
     * @brief Connect event
     * 
     * @param event 
     * @param window 
     * @param endpoint 
     * @param socket 
     * @param alert 
     * @return ** void 
     */
    void connect(const sf::Event &event, const sf::RenderWindow &window, asio::ip::tcp::endpoint &endpoint, asio::ip::tcp::socket &socket, WarningBox &alert);
    void connect(const sf::Event &event, const sf::RenderWindow &window, WarningBox &alert);

    protected:
    private:
        void getDefaultInput();

        InputBox _loginBox;
        InputBox _passwordBox;
        Button _connect;
        // ValidateIp _validator;
        std::string _login;
        std::string _password;
};

#endif /* !CONNECTION_HPP_ */
