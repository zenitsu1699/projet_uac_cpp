/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** UserCard
*/

#ifndef USERCARD_HPP_
#define USERCARD_HPP_

#include <SFML/Graphics.hpp>

#include "../../tools/AssetHandle.hpp"

class UserCard {
    public:
        UserCard();
        ~UserCard();

        /**
         * @brief Create UserCard
         * 
         * @param pos 
         * @param size 
         * @param name 
         * @param ready 
         * @param factors 
         * @return ** void 
         */
        void create(const sf::Vector2f &pos, const sf::Vector2f &size, const std::string &name, const std::string &ready, const sf::Vector2f &factors = {1, 1});

        /**
         * @brief Draw UserCard
         * 
         * @param window 
         * @return ** void 
         */
        void draw(sf::RenderWindow &window) const;

        /**
         * @brief Get the Position object
         * 
         * @return ** sf::Vector2f 
         */
        sf::Vector2f getPosition() const;

        /**
         * @brief Get the Size object
         * 
         * @return ** sf::Vector2f 
         */
        sf::Vector2f getSize() const;

        /**
         * @brief Get the Name object
         * 
         * @return ** std::string 
         */
        std::string getName() const;

        /**
         * @brief Set the Ready object
         * 
         * @param state 
         * @return ** void 
         */
        void setReady(const std::string &state);

        /**
         * @brief Set the Position object
         * 
         * @param pos 
         * @return ** void 
         */
        void setPosition(const sf::Vector2f &pos);

    protected:
    private:
        sf::RectangleShape _background;
        sf::Text _name;
        sf::Font _font;
        sf::Texture _readyTexture;
        sf::Texture _notReadyTexture;
        sf::Sprite _ready;
};

#endif /* !USERCARD_HPP_ */
