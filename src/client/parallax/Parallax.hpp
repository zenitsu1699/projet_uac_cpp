/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** Parallax
*/


#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include <vector>

#include "Layer.hpp"
#include "../../tools/AssetHandle.hpp"

using namespace std;

class Parallax {
    public:
        enum Layers {
            BACKGROUND,
            PLANET,
            FARTHEST,
            FARE,
            CLOSE,
            CLOSEST,
        };

        enum Direction {
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        Parallax();
        ~Parallax();

        /**
         * @brief Create Parallax
         * 
         * @param speed 
         * @return ** void 
         */
        void create(const int &speed);

        /**
         * @brief Update Parallax
         * 
         * @return ** void 
         */
        void update();

        /**
         * @brief Draw Parallax
         * 
         * @param window 
         * @return ** void 
         */
        void draw(sf::RenderWindow &window) const;

        /**
         * @brief Parallax events
         * 
         * @param event 
         * @return ** void 
         */
        void event(const sf::Event &event);

        /**
         * @brief Set the Direction object
         * 
         * @param direction 
         * @return ** void 
         */
        void setDirection(const std::vector<bool> &direction);

    protected:
    private:
        void fillEmptySpace(struct std::pair<float, std::pair<std::pair<Layer *, Layer *>, std::pair<Layer *, Layer *>>> iter);
        void setPosition(struct std::pair<float, std::pair<std::pair<Layer *, Layer *>, std::pair<Layer *, Layer *>>> iter);
        void add(const float &speed, const Layers &type, const bool &active);

        vector<pair<float, pair<pair<Layer *, Layer *>, pair<Layer *, Layer *>>>> _layersVec;
        sf::Texture _layerTextures[6];
        bool _direction[4];
        int _speed;

};

#endif /* !PARALLAX_HPP_ */