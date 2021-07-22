#include "../include/sfml-map.hpp"

sf2::Map::Map() {}

sf2::Map::Map
(
         std::string _filename,
         int _width,
         int _height,
         sf::Vector2f _tilesize
) : tileSize(_tilesize),width(_width),height(_height)
{
    std::ifstream is(_filename);
    std::string line;
    // generates mapTemplate[height][width]
    for (int i=0;i<_height;i++)
    {
        // Get line
        std::getline(is,line);
        line.erase(remove(line.begin(),line.end(),' '),line.end());

        std::vector<int> row;
        for (int j=0;j<_width;j++)
        {
            // Chars to integers
            int k = line[j] - '0';
            // push int to row
            row.push_back(k);
        }
        // push row to i
        coordsYX.push_back(row);
    }
}

void sf2::Map::sendTexture(sf::Texture* _tex)
{
    textures.push_back(_tex);
}

void sf2::Map::createVertexArrays()
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (coordsYX[i][j] != 0)
            {
                sf::VertexArray va(sf::Quads,4);
                va[0].position = sf::Vector2f(j*tileSize.x,i*tileSize.y);
                va[1].position = sf::Vector2f(j*tileSize.x+tileSize.x,i*tileSize.y);
                va[2].position = sf::Vector2f(j*tileSize.x+tileSize.x,i*tileSize.y+tileSize.y);
                va[3].position = sf::Vector2f(j*tileSize.x,i*tileSize.y+tileSize.y);
                va[0].texCoords = sf::Vector2f(0,0);
                va[1].texCoords = sf::Vector2f(tileSize.x,0);
                va[2].texCoords = tileSize;
                va[3].texCoords = sf::Vector2f(0,tileSize.y);

                if (coordsYX[i][j] == 1) // vertexArrays[0] , textures[0]
                {
                    if (vertexArrays.empty())
                        vertexArrays.push_back(std::vector<sf::VertexArray>());
                    vertexArrays[0].push_back(va);
                }
            }
        }
    }
}

void sf2::Map::draw(sf::RenderTarget& _target,sf::RenderStates _states) const
{
    for (int i=0;i<(int)vertexArrays[0].size();i++)
    {
        _target.draw(vertexArrays[0][i],textures[0]);
    }
}
