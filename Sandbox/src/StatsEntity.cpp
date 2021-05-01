#include <cassert>

#include "StatsEntity.h"

StatsEntity::StatsEntity()
{
	// load the font, assume success
	const auto success = _font.loadFromFile("fonts/JetBrainsMono-Regular.ttf");
	assert(success);

	// configure the font
	Stats.setFont(_font);
	Stats.setCharacterSize(24);
	Stats.setFillColor(sf::Color::Yellow);
}

void StatsEntity::update(double dt)
{
	// we output frametime in milliseconds
	// 16 ms -> 60 frames per second, our gold standard
	const auto text = "frametime: " + std::to_string(dt) + " s";
	Stats.setString(text);
}


