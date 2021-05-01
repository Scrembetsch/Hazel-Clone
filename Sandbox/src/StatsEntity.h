#pragma once

#include <SFML/Graphics.hpp>

class StatsEntity
{
public:
	StatsEntity();

	void update(double dt);

	sf::Text Stats;
private:
	sf::Font _font;
};

