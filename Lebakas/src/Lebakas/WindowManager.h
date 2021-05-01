#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Event.h"

class LEBAKAS_API WindowManager
{
public:
	WindowManager(std::uint32_t width = 1280, std::uint32_t height = 720, std::string title = "VOLLEGAS LEBAKAS!");
	~WindowManager();

	bool IsWindowOpen();
	void CloseWindow();

	std::uint32_t GetWindowHeight() const;
	std::uint32_t GetWindowWidth() const;

	Event GetLatestEvent();

	void Render();

	size_t AddDrawable(sf::Drawable* drawable);
	void RemoveDrawable(size_t index);
	void RemoveDrawable(sf::Drawable* drawable);

private:
	sf::RenderWindow* mWindow;
	std::vector<sf::Drawable*> mDrawObjects;
};