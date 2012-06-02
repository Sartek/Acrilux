#include "headers/TextureManager.hpp"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

int TextureManager::LoadTexture(std::string texture)
{
	bool allowLoad = true;
	int textureLocation;
	for(unsigned int i = 0;i<loadedTextures.size();i++)
	{
		if(loadedTextures[i] == texture)
		{
			allowLoad = false;
			textureLocation = i;
			break;
		}
	}

	if(allowLoad)
	{
		sf::Texture temptexture;
		temptexture.loadFromFile(texture);
		loadedTextures.push_back(texture);
		textureList.push_back(temptexture);
		textureLocation = textureList.size() - 1;
	}

	return textureLocation;
}

sf::Texture& TextureManager::GetTexture(int id)
{
	return textureList.at(id);
}
