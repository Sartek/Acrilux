#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    std::vector<sf::Texture> textureList;
    std::vector<std::string> loadedTextures;
public:
    TextureManager();
    ~TextureManager();

    int LoadTexture(std::string texture);
    sf::Texture& GetTexture(int id);
};

#endif // TEXTUREMANAGER
