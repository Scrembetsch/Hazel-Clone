#include "WindowManager.h"

WindowManager::WindowManager(std::uint32_t width, std::uint32_t height, std::string title)
{
	mWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

WindowManager::~WindowManager()
{
	delete mWindow;
}

bool WindowManager::IsWindowOpen()
{
	return mWindow->isOpen();
}

void WindowManager::CloseWindow()
{
	mWindow->close();
}

Event WindowManager::GetLatestEvent()
{
	sf::Event sfEvent;
	if (mWindow->pollEvent(sfEvent))
	{
		switch (sfEvent.type)
		{
			case sf::Event::Closed:
				return Event(Event::Type::CLOSE_WINDOW);

			case sf::Event::KeyPressed:
			{
				Event event(Event::Type::KEY_PRESSED);
				event.Key = static_cast<Device::Input::Key>(sfEvent.key.code);	// Cast is safe as enum is copied
				return event;
			}

			case sf::Event::KeyReleased:
			{
				Event event(Event::Type::KEY_RELEASED);
				event.Key = static_cast<Device::Input::Key>(sfEvent.key.code);	// Cast is safe as enum is copied
				return event;
			}

			default:
				break;
		}
	}
	return Event();
}

size_t WindowManager::AddDrawable(sf::Drawable* drawable)
{
	mDrawObjects.push_back(drawable);
	return mDrawObjects.size() - 1;
}

void WindowManager::RemoveDrawable(size_t index)
{
	mDrawObjects.erase(mDrawObjects.begin() + index);
}

void WindowManager::RemoveDrawable(sf::Drawable* drawable)
{
	mDrawObjects.erase(std::find(mDrawObjects.begin(), mDrawObjects.end(), drawable));
}

void WindowManager::Render()
{
	mWindow->clear();
	for (auto it = mDrawObjects.begin(); it != mDrawObjects.end(); it++)
	{
		mWindow->draw(**it);
	}
	mWindow->display();
}