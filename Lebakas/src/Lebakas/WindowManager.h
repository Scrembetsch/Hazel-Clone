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

	/// <summary>
	/// Checks if window is open
	/// </summary>
	/// <returns></returns>
	bool IsWindowOpen();
	/// <summary>
	/// Closes SFML window
	/// </summary>
	void CloseWindow();

	/// <summary>
	/// Get current Heightof window
	/// </summary>
	/// <returns></returns>
	std::uint32_t GetWindowHeight() const;
	/// <summary>
	/// Get current width of window
	/// </summary>
	/// <returns></returns>
	std::uint32_t GetWindowWidth() const;

	/// <summary>
	/// Get the oldest event of the sfml event queue
	/// </summary>
	/// <returns></returns>
	Event PollEvent();

	/// <summary>
	/// Renders all Drawables in DrawObjects
	/// </summary>
	void Render();

	/// <summary>
	/// Add drawable to list of objects that should be rendered
	/// </summary>
	/// <param name="drawable"></param>
	/// <returns></returns>
	size_t AddDrawable(sf::Drawable* drawable);
	/// <summary>
	/// Remove drawbale object from render list
	/// </summary>
	/// <param name="index"></param>
	void RemoveDrawable(size_t index);
	/// <summary>
	/// Remove drawbale object from render list
	/// </summary>
	/// <param name="drawable"></param>
	void RemoveDrawable(sf::Drawable* drawable);

private:
	sf::RenderWindow* mWindow;
	std::vector<sf::Drawable*> mDrawObjects;
};