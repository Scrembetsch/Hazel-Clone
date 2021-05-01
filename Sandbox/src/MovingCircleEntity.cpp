#include "MovingCircleEntity.h"

#include "VectorMath.h" 

MovingCircleEntity::MovingCircleEntity(const sf::Vector2f& position, float radius, const sf::Color& color, const sf::Vector2f& velocity, const sf::Rect<float>& worldBounds)
	: mShape()
	, _velocity(velocity)
{
	mShape.setPosition(position);
	mShape.setRadius(radius);
	mShape.setFillColor(color);
	// each entry represents the normal of a rectangle line (inwards facing) plus the line offset in normal direction
	// order of line representations: top, right, bottom, left
	_bounds = {
		std::make_pair(sf::Vector2f(0.f, 1.f), worldBounds.top + radius),
		std::make_pair(sf::Vector2f(-1.f, 0.f), worldBounds.left + worldBounds.width - radius),
		std::make_pair(sf::Vector2f(0.f, -1.f), worldBounds.top + worldBounds.height - radius),
		std::make_pair(sf::Vector2f(1.f, 0.f), worldBounds.left + radius)
	};
}

void MovingCircleEntity::update(double dt)
{
	float seconds = dt;
	// calculate the next position
	auto nextPosition = mShape.getPosition() + _velocity * seconds;

	// check for a potential collision against all bounds
	for (auto bound : _bounds)
	{
		const sf::Vector3f l(bound.first.x, bound.first.y, bound.second - mShape.getRadius());
		const sf::Vector3f p1(nextPosition.x, nextPosition.y, 1.f);

		const auto distance = VectorMath::dot(p1, l);

		// we have an intersection between circle and boundary
		if (distance <= 0.f)
		{
			const sf::Vector3f p0(mShape.getPosition().x, mShape.getPosition().y, 1.f);
			const sf::Vector3f v(_velocity.x, _velocity.y, 0.f);

			// calculate the exact time of collision
			const auto t = -VectorMath::dot(l, p0) / VectorMath::dot(l, v);

			// move the circle forward until it collides
			mShape.setPosition(mShape.getPosition() + _velocity * t);

			// calculate remaining time
			seconds -= t;

			// invert the movement direction
			const auto reverse = -_velocity;

			// calculate the reflection vector and take it as the new velocity
			_velocity = 2.f * VectorMath::dot(bound.first, reverse) * bound.first - reverse;

			// for the remaining time, move into the new direction
			nextPosition = mShape.getPosition() + _velocity * std::max(seconds, 0.f);

			break;
		}
	}

	mShape.setPosition(nextPosition);
}
