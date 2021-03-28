#pragma once
#include <SFML/Graphics.hpp>
class InputManager
{
public:

	bool isSpriteClicked(const sf::Sprite& sprite, sf::Mouse::Button button,
						 const sf::RenderWindow& window) const;

	bool isMousePointingSprite(const sf::Sprite& sprite, const sf::RenderWindow& window) const;
	
	sf::Vector2f getMousePosition(const sf::RenderWindow& window) const;

};