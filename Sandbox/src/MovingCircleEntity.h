#pragma once
#include <SFML/Graphics.hpp>

class MovingCircleEntity
{
public:
	MovingCircleEntity(const sf::Vector2f& position,
		float radius,
		const sf::Color& color,
		const sf::Vector2f& velocity, 
		const sf::Rect<float>& worldBounds);
	virtual ~MovingCircleEntity() = default;
	
	void update(double dt);
	
	sf::CircleShape mShape;
private:
	sf::Vector2f _velocity;

	std::vector<std::pair<sf::Vector2f, float>> _bounds;
};

