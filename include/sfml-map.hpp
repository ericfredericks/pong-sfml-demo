#ifndef SFML2_MAP_H
#define SFML2_MAP_H

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace sf2
{
    class Map : public sf::Drawable
    {
    public:
        Map();
        Map(std::string _filename,int _width,int _height,sf::Vector2f _tilesize);
        void createVertexArrays();
        void draw(sf::RenderTarget&,sf::RenderStates) const;
        void sendTexture(sf::Texture* _tex);
        std::vector<std::vector<int>> coordsYX;
        int height;
        int width;
        sf::Vector2f tileSize;
    private:
        std::vector<sf::Texture*> textures;
        std::vector<std::vector<sf::VertexArray>> vertexArrays;
    };
}
#endif
