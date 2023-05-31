/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Utils
*/


#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <SFML/Graphics.hpp>
#include <math.h>

class Utils {
    public:
        Utils();
        ~Utils();

        /**
         * @brief Get vector magnitude
         * 
         * @param vector 
         * @return ** float 
         */
        float vectorMagnitude(const sf::Vector2f &vector) const;

        /**
         * @brief Get the Random Normalized Vector object
         * 
         * @return ** sf::Vector2f 
         */
        sf::Vector2f getRandomNormalizedVector() const;

    protected:
    private:
};

#endif /* !UTILS_HPP_ */