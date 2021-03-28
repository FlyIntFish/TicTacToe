#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include "Asset.h"

class AssetManager
{
public:

	AssetManager() { }
	AssetManager(const AssetManager&) = delete;

	void loadFont(const std::string& filePath, const std::string& name);
	void loadTexture(const std::string& filePath, const std::string& name);

	bool containFont(const std::string& name) const;
	bool containTexture(const std::string& name) const;

	const sf::Texture& getTexture(const std::string& name) const;
	const sf::Font& getFont(const std::string& name) const;

	const std::map<std::string, sf::Texture>::const_iterator
		getTextureIterator(const std::string& name) const;

private:

	Asset<sf::Texture> textures;
	Asset<sf::Font> fonts;

};