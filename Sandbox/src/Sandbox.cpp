#include <Lebakas.h>
#include "Lebakas/Time.h"
#include "CircleEntityGenerator.h"
#include "StatsEntity.h"

class Sandbox : public Lebakas::Application
{
public:
	Sandbox()
		: Application()
	{
		unsigned int entities = 1000;
		mBounds = sf::Rect<float>(0.0f, 0.0f, static_cast<float>(mRenderer.GetWindowWidth()), static_cast<float>(mRenderer.GetWindowHeight()));
		for (unsigned int i = 0; i < entities; ++i)
		{
			mEntities.emplace_back(CircleEntityGenerator::generateInBounds(mBounds));
		}

		for (auto it = mEntities.begin(); it != mEntities.end(); it++)
		{
			mRenderer.AddDrawable(&((*it)->mShape));
		}
		mRenderer.AddDrawable(&(mStats.mStats));
	}

	~Sandbox()
	{
	}

	virtual void FixedUpdate(double deltaTime)
	{
		//LEBAKAS_INFO(deltaTime);
		if (Device::Input::WasKeyPressed(Device::Input::Key::Up))
		{
			Time::SetFixedFps(Time::GetFixedFps() + 5);
		}
		else if (Device::Input::WasKeyPressed(Device::Input::Key::Down))
		{
			if (Time::GetFixedFps() >= 6)
			{
				Time::SetFixedFps(Time::GetFixedFps() - 5);
			}
		}
		if (Device::Input::WasKeyPressed(Device::Input::Key::Right))
		{
			Time::SetVSyncFps(Time::GetVSyncFps() + 5);
		}
		else if (Device::Input::WasKeyPressed(Device::Input::Key::Left))
		{
			if (Time::GetVSyncFps() > 5)
			{
				Time::SetVSyncFps(Time::GetVSyncFps() - 5);
			}
			else if (Time::GetVSyncFps() > 1)
			{
				Time::SetVSyncFps(Time::GetVSyncFps() - 1);
			}
		}
		for (auto entity : mEntities)
		{
			entity->update(deltaTime);
		}
		mStats.update(deltaTime);
	}

	sf::Rect<float> mBounds;
	std::vector<MovingCircleEntity*> mEntities;
	StatsEntity mStats;
};

Lebakas::Application* Lebakas::CreateApplication()
{
	return new Sandbox();
}