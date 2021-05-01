#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual ~Entity() = default;
	virtual void update(double dt) = 0;
};