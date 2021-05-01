#pragma once

#include <SFML/Graphics.hpp>

class StatsEntity
{
public:
	StatsEntity();

	void update(double dt);

	sf::Text mStats;
private:
	sf::Font mFont;
};

