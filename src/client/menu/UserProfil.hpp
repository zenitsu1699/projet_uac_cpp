/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** UserProfil
*/


#ifndef UserProfil_HPP_
#define UserProfil_HPP_

#include <SFML/Graphics.hpp>
#include <asio.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include "../common/InputBox.hpp"
#include "../common/Button.hpp"
// #include "ValidateIp.hpp"
#include "../common/WarningBox.hpp"

class UserProfil {
    public:
        UserProfil();
        ~UserProfil();

    /**
     * @brief Create UserProfil
     * 
     * @param background 
     * @return ** void 
     */
    void create(const sf::RectangleShape &background);

    /**
     * @brief UserProfil events
     * 
     * @param event 
     * @param window 
     * @return ** void 
     */
    void event(const sf::Event &event, const sf::RenderWindow &window);

    /**
     * @brief Update UserProfil
     * 
     * @param window 
     * @param background 
     * @param animationEnd 
     * @param isDrawn 
     * @return ** void 
     */
    void update(const sf::RenderWindow &window, const sf::RectangleShape &background, const bool &animationEnd, const bool &isDrawn);

    /**
     * @brief Draw UserProfil
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
    void connect(const sf::Event &event, const sf::RenderWindow &window, WarningBox &alert);

    protected:
    private:
        void getDefaultInput();

        InputBox _nameBox;
        InputBox _loginBox;
        InputBox _passwordBox;
        Button _newletter;
        Button _subscriber;
        Button _disconnect;
        // ValidateIp _validator;
        std::string _login;
        std::string _name;
        std::string _password;
};

#endif /* !UserProfil_HPP_ */
