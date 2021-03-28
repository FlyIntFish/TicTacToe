#include "AssetManager.h"

void AssetManager::loadFont(const std::string& filePath, const std::string& name)
{
	fonts.load(filePath, name);
}

void AssetManager::loadTexture(const std::string& filePath, const std::string& name) 
{
	textures.load(filePath, name);
}

bool AssetManager::containFont(const std::string& name) const
{
	return fonts.contain(name);
}

bool AssetManager::containTexture(const std::string& name) const 
{
	return fonts.contain(name);
}

const sf::Texture& AssetManager::getTexture(const std::string& name) const
{
	return textures.get(name);
}

const sf::Font& AssetManager::getFont(const std::string& name) const 
{
	return fonts.get(name);
}

const std::map<std::string, sf::Texture>::const_iterator AssetManager::getTextureIterator(const std::string& name) const
{
	return textures.getIterator(name);
}

