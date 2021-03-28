#include "InputManager.h"

bool InputManager::isSpriteClicked(const sf::Sprite& sprite, sf::Mouse::Button button,
                    const sf::RenderWindow& window) const
{
    if (sf::Mouse::isButtonPressed(button) && isMousePointingSprite(sprite, window))
        return true;
    return false;
}

bool InputManager::isMousePointingSprite(const sf::Sprite& sprite, const sf::RenderWindow& window) const
{
    return sprite.getGlobalBounds().contains(getMousePosition(window));
}

sf::Vector2f InputManager::getMousePosition(const sf::RenderWindow& window) const
{
    return sf::Vector2f(sf::Mouse::getPosition(window));
}
