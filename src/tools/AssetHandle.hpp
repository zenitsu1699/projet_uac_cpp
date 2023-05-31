/*
** PROJECT, 2023
** By Gérard TOUDOGUIN
** File description:
** AssetHandle
*/


#ifndef ASSETHANDLE_HPP_
#define ASSETHANDLE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <map>

template<typename T>
class AssetHandle {
    public:
        ~AssetHandle() {};

        /**
         * @brief Get the instance of the FontManager singelton
         *
         * @return ** FontManager &instance of FontManager
         */
        static AssetHandle &getAssetHandle() {
            static AssetHandle instance = AssetHandle();
            return instance;
        }

        /**
         * @brief Get asset, if asset already load just return the asset associeted to,
         * IMPORTANT !!!
         * if the type of asset doesn't have loadFromFile method, there will be an error
         *
         * @param path path to the font
         * @return ** template<typename T>
         */
        T getAsset(const std::string &path) {
            T asset;

            if (fonts.find(path) != fonts.end())
                return fonts[path];
            if (asset.loadFromFile(path))
                fonts.insert(std::pair<std::string, T>(path, asset));
            return asset;
        }

    protected:
    private:
        AssetHandle() {};

        std::map<const std::string, T> fonts;
};

#endif /* !ASSETHANDLE_HPP_ */
